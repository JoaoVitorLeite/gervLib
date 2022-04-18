#include <iostream>
#include <ParserArguments.h>
#include <Dataset.h>
#include <Hermes.h>
#include <fstream>

using namespace std;

/*

  -DATASET_NAME => Caminho de um dataset(não serializado)
  -DATASET_SERIALIZED_NAME => Caminho de um dataset(serializado)
  ** -DATASET_CARDINALITY => Cardinalidade do dataset(não serializado)
  ** -DATASET_DIMENSIONALITY => Dimensionalidade do dataset(não serializado)
  ** -DATASET_SEPARATOR => Caracter separador do dataset(não serializado) !DEFAULT = ,
  -DISTANCE_FUNCTION => Função de distância !DEFAULT = EUCLIDEAN
  -SAMPLE_SIZE => Tamanho da amostra
  -PATH_SAVE_RESULT => Caminho para salvar o resultado !DEFAULT = outputDim_ + {Distance Function} + .txt
  -SEED => Seed !DEFAULT = 0

*/


int main(int argc, char *argv[])
{

    if((argc - 1) % 2 != 0)
        throw std::invalid_argument("Invalid number of arguments !_!");
    else
    {

        std::string* dataset_name = nullptr;
        std::string* dataset_serialized_name = nullptr;
        size_t* dataset_cardinality = nullptr;
        size_t* dataset_dimensionality = nullptr;
        std::string* dataset_separator = new std::string(",");
        std::string* distance_function = new std::string("EUCLIDEAN");
        size_t* sample_size = nullptr;
        std::string* path_save_result = new std::string("outputDim_" + *distance_function + ".txt");
        Dataset* dataset;
        size_t* seed = new size_t(0);
        DistanceFunction<Instance>* df;
        ParserArguments parser = ParserArguments();

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
            else if(key == "-SAMPLE_SIZE")
                sample_size = new size_t(std::stoi(value));
            else if(key == "-PATH_SAVE_RESULT")
                path_save_result = new std::string(value);
            else if(key == "-SEED")
                seed = new size_t(std::stoi(value));
            else{
                //cout << key << endl;
                throw std::invalid_argument("Invalid key !_!");
            }

        }

        //Read Dataset
        if((dataset_name != nullptr) || (dataset_serialized_name != nullptr))
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

        //Read Distance Function
        if(distance_function != nullptr)
            df = parser.parseDistanceFunction(*distance_function);
        else
            throw std::invalid_argument("Can't read distance function");


        dataset->setSeed(*seed);
        size_t ans = dataset->intrinsicDimensionality(df, *sample_size);
        *path_save_result = "outputDim_" + *distance_function + ".txt"
        std::ofstream file(*path_save_result);
        file << *dataset_name
             << ","
             << *distance_function
             << endl;
        file << ans
             << endl;
        file.close();

    }

    return 0;

}

