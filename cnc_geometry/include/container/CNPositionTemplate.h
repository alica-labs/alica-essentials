/*
 * CNPositionTemplate.h
 *
 *  Created on: 07.11.2016
 *      Author: Philipp Mandler
 */

#ifndef CNC_GEOMETRY_CONTAINER_CNPOSITIONTEMPLATE_H_
#define CNC_GEOMETRY_CONTAINER_CNPOSITIONTEMPLATE_H_

#include "geometry_msgs/Pose2D.h"
#include "container/CNVec2DTemplate.h"
#include <type_traits>

namespace geometry
{

template <class T> class CNPositionTemplate : public geometry_msgs::Pose2D
{
  public:
	std::shared_ptr<T> clone()
	{
		return std::make_shared<T>(this->x, this->y, this->theta);
	}

    double distanceTo(T pos)
    {
    	T delta = this - pos;
    	return delta->length();
    }

    double length()
	{
    	return sqrt(x * x + y * y);
    }

};


// Operators

// Self

template <typename T>
typename std::enable_if<std::is_base_of<CNPositionTemplate<T>, T>::value, std::shared_ptr<T>>::type
operator+(const std::shared_ptr<T> &left, const std::shared_ptr<T> &right)
{
    return std::make_shared<T>(
    		left->x + right->x,
			left->y + right->y,
			left->theta + right->theta);
}

template <typename T>
typename std::enable_if<std::is_base_of<CNPositionTemplate<T>, T>::value, std::shared_ptr<T>>::type
operator-(const std::shared_ptr<T> &left, const std::shared_ptr<T> &right)
{
    return std::make_shared<T>(
    		left->x - right->x,
			left->y - right->y,
			left->theta - right->theta);
}

// Scalar

template <typename T>
typename std::enable_if<std::is_base_of<CNPositionTemplate<T>, T>::value, std::shared_ptr<T>>::type
operator/(const std::shared_ptr<T> &left, const double &right)
{
	return std::make_shared<T>(
			left->x / right,
			left->y / right,
			left->theta);
}

template <typename T>
typename std::enable_if<std::is_base_of<CNPositionTemplate<T>, T>::value, std::shared_ptr<T>>::type
operator*(const std::shared_ptr<T> &left, const double &right)
{
	return std::make_shared<T>(
			left->x * right,
			left->y * right,
			left->theta);
}

} /* namespace geometry */

#endif /* CNC_GEOMETRY_CONTAINER_CNPOSITIONTEMPLATE_H_ */
