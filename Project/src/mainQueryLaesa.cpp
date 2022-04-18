#include <iostream>
#include <Dataset.h>
#include <Hermes.h>
#include <fstream>
#include <chrono>
#include <ParserArguments.h>
#include <Laesa.h>

using namespace std;

/* KEYWORDS

  -PATH_INDEX => Caminho para o Laesa serializado
  -DATASET_NAME => Caminho de um dataset(não serializado)
  -DATASET_SERIALIZED_NAME => Caminho de um dataset(serializado)
  ** -DATASET_CARDINALITY => Cardinalidade do dataset(não serializado)
  ** -DATASET_DIMENSIONALITY => Dimensionalidade do dataset(não serializado)
  ** -DATASET_SEPARATOR => Caracter separador do dataset(não serializado) !DEFAULT = ,
  -DISTANCE_FUNCTION => Função de distância
  -K_MAX => Número máximo para k !DEFAULT = 50
  -NUM_QUERY => Número de elementos de consulta
  -PATH_SAVE_RESULTS
  -KNN_SHAPIRO => Booleano sobre método de consulta[0(FALSE)/1(TRUE)] !DEFAULT = 1

*/

int main(int argc, char *argv[])
{

    if((argc-1) % 2 != 0)
        throw std::invalid_argument("Invalid number of arguments !_!");
    else
    {

        std::string* path_index = nullptr;
        std::string* dataset_name = nullptr;
        std::string* dataset_serialized_name = nullptr;
        size_t* dataset_cardinality = nullptr;
        size_t* dataset_dimensionality = nullptr;
        std::string* dataset_separator = nullptr;
        std::string* distance_function = nullptr;
        size_t* k_max = nullptr;
        size_t* num_query = nullptr;
        std::string* path_save_results = nullptr;
        std::string* knn_shapiro = nullptr;

        ParserArguments parser = ParserArguments();
        Dataset* train = nullptr;
        Dataset* test = nullptr;
        DistanceFunction<Instance>* df = nullptr;
        Pivot* pivot = nullptr;
        Laesa* laesa = nullptr;

        for(int x = 1; x < argc; x += 2)
        {

            std::string key = argv[x];
            for(size_t x = 0; x < key.size(); x++)
                key[x] = std::toupper(key[x]);

            std::string value = argv[x+1];

            if(key == "-PATH_INDEX")
                path_index = new std::string(value);
            else if(key == "-DATASET_NAME")
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
            else if(key == "-K_MAX")
                k_max = new size_t(std::stoi(value));
            else if(key == "-NUM_QUERY")
                num_query = new size_t(std::stoi(value));
            else if(key == "-PATH_SAVE_RESULTS")
                path_save_results = new std::string(value);
            else if(key == "-KKN_SHAPIRO")
                knn_shapiro = new std::string(value);
            else{
                //cout << key << endl;
                throw std::invalid_argument("Invalid key !_!");
            }
        }

        //Read Dataset
        if(dataset_name != nullptr)
        {

            if((dataset_cardinality != nullptr) && (dataset_dimensionality != nullptr))
                test = new Dataset(*dataset_name, *dataset_cardinality, *dataset_dimensionality);
            else
            {

                if(dataset_separator != nullptr)
                    test = new Dataset(*dataset_name, *dataset_separator);
                else
                    test = new Dataset(*dataset_name, ",");

            }

        }
        else
            throw std::invalid_argument("Can't read Test Dataset");

        if(dataset_serialized_name != nullptr)
        {

            train = new Dataset();
            train->loadFromFile(*dataset_serialized_name);

        }

        //Read K_MAX
        if(k_max == nullptr)
            k_max = new size_t(50);

        //Check NUM_QUERY
        if(num_query == nullptr)
            num_query = new size_t(test->getCardinality());

        //Check PATH_SAVE_RESULTS
        if(path_save_results == nullptr)
            path_save_results = new std::string("");

        //Check KNN_SHAPIRO
        if(knn_shapiro == nullptr)
            knn_shapiro = new std::string("1");

        //Read Distance Function
        if(distance_function != nullptr)
            df = parser.parseDistanceFunction(*distance_function);
        else
            throw std::invalid_argument("Can't read distance function");

        //Read LAESA
        laesa = new Laesa();
        if(path_index == nullptr)
            throw std::invalid_argument("Can't read LAESA !_!");
        else
            laesa->loadFromFile(*path_index);

        laesa->setDistanceFunction(df);

        std::string names[] = {"RANDOM", "GNAT", "CONVEX", "KMEDOIDS", "MAXSEPARETED", "MAXVARIANCE", "SELECTION", "PCA", "SSS"};

        //QUERY EXECUTION

        for(size_t x = 5; x <= *k_max; x += 5)
        {

            std::string fileName = *path_save_results + names[laesa->getPivot()->getPivotType()] + "_" + std::to_string(x) + ".csv";
            std::ofstream file(fileName);

            file << *distance_function + ",A,A\n";
            file << std::to_string(laesa->getNumberOfPivots()) + ",A,A\n";
            file << parser.getPivotName(laesa->getPivot()->getPivotType()) + ",A,A\n";
            file << std::to_string(x) + ",A,A\n";
            file << std::to_string(*num_query) + ",A,A\n";
            file << "k,Time,Count\n";

            for(size_t y = 0; y < *num_query; y++)
            {

                if(*knn_shapiro == "1")
                {

                    auto start = std::chrono::steady_clock::now();
                    laesa->knnShapiro(train, test->instance(y), x);
                    auto end = std::chrono::steady_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    file << std::to_string(x) + "," + std::to_string(elapsed.count()) + "," + std::to_string(laesa->getDistCount()) + "\n";

                }
                else
                {

                    auto start = std::chrono::steady_clock::now();
                    laesa->knn(train, test->instance(y), x);
                    auto end = std::chrono::steady_clock::now();
                    auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

                    file << std::to_string(x) + "," + std::to_string(elapsed.count()) + "," + std::to_string(laesa->getDistCount()) + "\n";

                }

            }

        }

        //DELETE POINTERS
        if(path_index != nullptr)
            delete path_index;
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
        if(k_max != nullptr)
            delete k_max;
        if(num_query != nullptr)
            delete num_query;
        if(path_save_results != nullptr)
            delete path_save_results;
        if(knn_shapiro != nullptr)
            delete knn_shapiro;
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

