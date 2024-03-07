#ifndef FEATURE_HPP
#define FEATURE_HPP

#include "Func.hpp"

void Function_Variant(variant<OX, CAT, DOG> animal)
{
   int index = animal.index();
		switch (index)
		{
		case 0: {
			OX ox = std::get<0>(animal);
			ox.oxFun();
			break;
		}

		case 1:
		{
			CAT cat = std::get<1>(animal);
			cat.catFun();
			break;
		}
		case 2:
		{
			DOG dog = std::get<2>(animal);
			dog.dogFun();
			break;
		}
		};
		line();
}

#endif // FEATURE_HPP
