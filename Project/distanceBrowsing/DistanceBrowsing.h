#ifndef DISTANCEBROWSING_H
#define DISTANCEBROWSING_H

#include "../hermes/Hermes.h"
#include "../utils/Dataset.h"
#include <vector>
#include "../kdtree/Node.h"



class DistanceBrowsing
{

    //PRIVATE
    private:
        DistanceFunction<Instance>* df;

    //PUBLIC
    public:

        //Constructors and destructors
        DistanceBrowsing(DistanceFunction<Instance>* distanceFunction);
        DistanceBrowsing();

        //Methods
        bool isInterval(double infBound, double supBound, double test);
        double minDist(Instance* sq, std::vector<DynamicArray<double>> bounds);
        double maxDist(Instance* sq, std::vector<DynamicArray<double>> bounds);

        //Setters
        void setDistanceFunction(DistanceFunction<Instance>* distanceFunction);


};

/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/
/*//////////////////////////////////////////////////////////////////////////////////////////////////////////////*/


DistanceBrowsing::DistanceBrowsing(DistanceFunction<Instance>* distanceFunction)
{

    setDistanceFunction(distanceFunction);

}



DistanceBrowsing::DistanceBrowsing()
{

    setDistanceFunction(nullptr);

}



bool DistanceBrowsing::isInterval(double infBound, double supBound, double test)
{

//    bool ans;

//    if(infBound < 0)
//    {

//        ans = (std::abs(infBound) < test) && (test <= supBound);

//    }
//    else if(supBound < 0)
//    {

//        ans = (infBound <= test) && (test < std::abs(supBound));

//    }
//    else if((infBound < 0) && (supBound < 0))
//    {

//        ans = (std::abs(infBound) < test) && (test < std::abs(supBound));

//    }
//    else
//    {

//        ans = (infBound <= test) && (test <= supBound);

//    }

//    return ans;

    return ((test >= infBound) && (test <= supBound));

}



double DistanceBrowsing::minDist(Instance* sq, std::vector<DynamicArray<double>> bounds)
{

//    Instance* point = new Instance(0, sq->getSize());

//    for(size_t x = 0; x < bounds.size(); x++)
//    {

//        if(isInterval(bounds[x].array[0], bounds[x].array[1], sq->get(x)))
//        {

//            //std::cout << "VALOR NO INTERVALO" << std::endl;
//            point->set(x, sq->get(x));

//        }
//        else
//        {

//            double infBoundaryRegion = std::abs(std::abs(bounds[x].array[0]) - sq->get(x)),
//                    supBoundaryRegion = std::abs(std::abs(bounds[x].array[1]) - sq->get(x));

//            //std::cout << "INF BOUNDARY REGION = " << infBoundaryRegion << std::endl;
//            //std::cout << "SUP BOUNDARY REGION = " << supBoundaryRegion << std::endl;

//            if(infBoundaryRegion <= supBoundaryRegion)
//            {

//                point->set(x, std::abs(bounds[x].array[0]));

//            }
//            else
//            {

//                point->set(x, std::abs(bounds[x].array[1]));

//            }

//        }

//        //std::cout << "\n\n";

//    }

//    double ans =  df->getDistance(*point, *sq);

//    delete point;

//    return ans;

    double answer = -1.0;
    double candidateV;
    Instance* limTeorico = new Instance(0, bounds.size());

    bool within = true;

    for(size_t x = 0; x < bounds.size(); x++)
    {

        candidateV = std::numeric_limits<double>::max();

        if(!isInterval(std::abs(bounds[x].array[0]), std::abs(bounds[x].array[1]), sq->get(x)))
        {

            within = false;

            candidateV = std::min(candidateV, std::abs(sq->get(x) - std::abs(bounds[x].array[0])));
            candidateV = std::min(candidateV, std::abs(sq->get(x) - std::abs(bounds[x].array[1])));

        }
        else
        {

            candidateV = sq->get(x);

        }

        limTeorico->set(x, candidateV);

    }

    if (within)
    {

        answer = 0.0;

    }
    else
    {

        answer = df->getDistance(*sq, *limTeorico);

    }


    return answer;

}



double DistanceBrowsing::maxDist(Instance* sq, std::vector<DynamicArray<double>> bounds)
{

//    Instance* point = new Instance(0, sq->getSize());

//    for(size_t x = 0; x < bounds.size(); x++)
//    {

//        if(isInterval(bounds[x].array[0], bounds[x].array[1], sq->get(x)))
//        {

//            point->set(x, sq->get(x));

//        }
//        else
//        {

//            double infBoundaryRegion = std::abs(bounds[x].array[0]) + sq->get(x),
//                    supBoundaryRegion = std::abs(bounds[x].array[1]) + sq->get(x);

//            if(infBoundaryRegion <= supBoundaryRegion)
//            {

//                point->set(x, std::abs(bounds[x].array[0]));

//            }
//            else
//            {

//                point->set(x, std::abs(bounds[x].array[1]));

//            }

//        }

//    }

//    double ans =  df->getDistance(*point, *sq);

//    delete point;

//    return ans;

    double answer = -1.0;
    double candidateV;
    Instance* limTeorico = new Instance(0, bounds.size());

    bool within = true;

    for(size_t x = 0; x < bounds.size(); x++)
    {

        candidateV = std::numeric_limits<double>::max();

        if(!isInterval(std::abs(bounds[x].array[0]), std::abs(bounds[x].array[1]), sq->get(x)))
        {

            within = false;

            candidateV = std::min(candidateV, sq->get(x) + std::abs(bounds[x].array[0]));
            candidateV = std::min(candidateV, sq->get(x) + std::abs(bounds[x].array[1]));

        }
        else
        {

            candidateV = sq->get(x);

        }

        limTeorico->set(x, candidateV);

    }

    if (within)
    {

        answer = 0.0;

    }
    else
    {

        answer = df->getDistance(*sq, *limTeorico);

    }


    return answer;


}



void DistanceBrowsing::setDistanceFunction(DistanceFunction<Instance>* distanceFunction)
{

    df = distanceFunction;

}

#endif // DISTANCEBROWSING_H
