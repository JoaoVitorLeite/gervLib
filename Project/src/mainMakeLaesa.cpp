#include <iostream>
#include <Dataset.h>
#include <Hermes.h>
#include <fstream>
#include <chrono>
#include <ParserArguments.h>
#include <Laesa.h>

using namespace std;

/* KEYWORDS

  -DATASET_NAME => Caminho de um dataset(não serializado)
  -DATASET_SERIALIZED_NAME => Caminho de um dataset(serializado)
  ** -DATASET_CARDINALITY => Cardinalidade do dataset(não serializado)
  ** -DATASET_DIMENSIONALITY => Dimensionalidade do dataset(não serializado)
  ** -DATASET_SEPARATOR => Caracter separador do dataset(não serializado) !DEFAULT = ,
  -DISTANCE_FUNCTION => Função de distância
  -PIVOT_TYPE => Pivot
  ** -SAMPLE_SIZE_PIVOT => Tamanho da amostra para gerar os pivôs
  ** -NUM_PIVOTS => Número de pivôs !DEFAULT = Calcular dimensionalidade intrínseca([MIN = 2] <= NUM_PIVOTS <= [MAX = Dimensionality])
  ** -PIVOT_OPTIONAL => Parâmetro opcional(o selection e kmedoids não vão precisar, mas o SSS nem sempre funciona com parâmetro adicional fixo, veja nos testes unitários...)
  -SEED = Seed
  -PATH_SAVE_INDEX => Caminho onde salvar o índice !DEFAUL = LAESA_{DISTANCE_FUNCTION_NAME}_{PIVOT_NAME}.dat
  -PATH_SAVE_DATASET => Caminho para salvar dataset serializado

*/

int main(int argc, char *argv[])
{

    if((argc-1) % 2 != 0)
        throw std::invalid_argument("Invalid number of arguments !_!");
    else
    {

        std::string* dataset_name = nullptr;
        std::string* dataset_serialized_name = nullptr;
        size_t* dataset_cardinality = nullptr;
        size_t* dataset_dimensionality = nullptr;
        std::string* dataset_separator = nullptr;
        std::string* distance_function = nullptr;
        std::string* pivot_type = nullptr;
        double* sample_size_pivot = nullptr;
        size_t* num_pivots = nullptr;
        string* pivot_optional = nullptr;
        size_t* seed = nullptr;
        std::string* path_save_index = nullptr;
        std::string* path_save_dataset = nullptr;

        ParserArguments parser = ParserArguments();
        Dataset* dataset = nullptr;
        DistanceFunction<Instance>* df = nullptr;
        Pivot* pivot = nullptr;
        Laesa* laesa = nullptr;

        for(int x = 1; x < argc; x += 2)
        {

            std::string key = argv[x];
            for(size_t x = 0; x < key.size(); x++)
                key[x] = std::toupper(key[x]);

            std::string value = argv[x+1];

            if(key == "-DATASET_NAME")
                dataset_name = new std::string(value);
            else if(key == "-DATASET_SERIALIZED_NAME")
                dataset_serialized_name = new std::string(value);
            else if(key == "-DATASET_CARDINALITY")
                dataset_cardinality = new size_t(std::stoi(value));
            else if(key == "-DATASET_DIMENSIONALITY")
                dataset_dimensionality = new size_t(std::stoi(value));
            else if(key == "-DATASET_SEPARATOR")
                dataset_separator = new std::string(value);
            else if(key == "-DISTANCE_FUNCTION")
                distance_function = new std::string(value);
            else if(key == "-PIVOT_TYPE")
                pivot_type = new std::string(value);
            else if(key == "-SAMPLE_SIZE_PIVOT")
                sample_size_pivot = new double(std::stod(value));
            else if(key == "-NUM_PIVOTS")
                num_pivots = new size_t(std::stoi(value));
            else if(key == "-PIVOT_OPTIONAL")
                pivot_optional = new std::string(value);
            else if(key == "-SEED")
                seed = new size_t(std::stoi(value));
            else if(key == "-PATH_SAVE_INDEX")
                path_save_index = new std::string(value);
            else if(key == "-PATH_SAVE_DATASET")
                path_save_dataset = new std::string(value);
            else{
                //cout << key << endl;
                throw std::invalid_argument("Invalid key !_!");
            }
        }

        //Read Dataset
        if(dataset_name != nullptr || dataset_serialized_name != nullptr)
        {

            if(dataset_name != nullptr)
            {

                if((dataset_cardinality != nullptr) && (dataset_dimensionality != nullptr))
                    dataset = new Dataset(*dataset_name, *dataset_cardinality, *dataset_dimensionality);
                else if(dataset_separator != nullptr)
                {

                    if(dataset_separator != nullptr)
                        dataset = new Dataset(*dataset_name, *dataset_separator);
                    else
                        dataset = new Dataset(*dataset_name, ",");

                }
                else
                    throw std::invalid_argument("Can't read dataset !_!");

            }
            else
            {

                dataset = new Dataset();
                dataset->loadFromFile(*dataset_name);

            }

        }
        else
            throw std::invalid_argument("Can't read dataset !_!");

        //Read seed
        if(seed == nullptr)
            seed = new size_t(0);


        //Read Distance Function
        if(distance_function != nullptr)
            df = parser.parseDistanceFunction(*distance_function);
        else
            throw std::invalid_argument("Can't read distance function");

        //Read Pivot
        if(pivot_type != nullptr)
        {

            std::string aux = *pivot_type + ",";

            if(num_pivots == nullptr)
                num_pivots = new size_t(dataset->intrinsicDimensionality(df, dataset->getCardinality()*0.1));

            if(sample_size_pivot == nullptr)
                sample_size_pivot = new double(0.1);

            aux += std::to_string(*sample_size_pivot);

            if(pivot_optional != nullptr)
            {

                aux += ",";
                aux += *pivot_optional;

            }

            pivot = parser.parsePivot(aux,",",dataset,df,*num_pivots,*seed);

        }
        else
            throw std::invalid_argument("Can't read pivot");

        //Create LAESA
        laesa = new Laesa(dataset, df, pivot);
        if(path_save_index == nullptr)
        {

            std::string fileName = "LAESA_" + *distance_function + "_" + *pivot_type + ".dat";
            path_save_index = new std::string(fileName);

        }
        laesa->saveToFile(*path_save_index);

        if(dataset_serialized_name == nullptr)
        {

            if(path_save_dataset != nullptr)
                dataset->saveToFile(*path_save_dataset);
            else
                throw std::invalid_argument("Can't save dataset !_!");

        }

        //DELETE POINTERS
        if(dataset_name != nullptr)
            delete dataset_name;
        if(dataset_serialized_name != nullptr)
            delete dataset_serialized_name;
        if(dataset_cardinality != nullptr)
            delete dataset_cardinality;
        if(dataset_dimensionality != nullptr)
            delete dataset_dimensionality;
        if(dataset_separator != nullptr)
            delete dataset_separator;
        if(distance_function != nullptr)
            delete distance_function;
        if(pivot_type != nullptr)
            delete pivot_type;
        if(sample_size_pivot != nullptr)
            delete sample_size_pivot;
        if(num_pivots != nullptr)
            delete num_pivots;
        if(pivot_optional != nullptr)
            delete pivot_optional;
        if(seed != nullptr)
            delete seed;
        if(path_save_index != nullptr)
            delete path_save_index;
        if(path_save_dataset != nullptr)
            delete path_save_dataset;
//        if(dataset != nullptr)
//            delete dataset;
        if(df != nullptr)
            delete df;
        if(pivot != nullptr)
            delete pivot;
        if(laesa != nullptr)
            delete laesa;

    }

    return 0;

}

