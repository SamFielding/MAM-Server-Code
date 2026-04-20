#pragma once
#include "functional"
#include "algorithm"
#include "vector"


template<typename...Params>
class Delegate
{
public:

	template<typename T>
	void bind(T* object, void (T::* func)(Params...))
	{
		functList.emplace_back([object, func](Params...parameters) {(object->*func)(parameters...); });
		
	}

	template<typename T>
	void unbind(T* object, void(T::* func)(Params...))
	{
		functList.erase(std::remove(functList.begin(), functList.end(), func), functList.end());
	}

	void invoke(Params... parameters)
	{
		for (auto& f : functList)
		{
			f(parameters...);
		}
	}

private:

	std::vector<std::function<void(Params...)>> functList;


};

