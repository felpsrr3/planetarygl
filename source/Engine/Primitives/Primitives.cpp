#include "Primitives.h"

namespace primitives
{
	float* GenCircleVertex(float radius)
	{
		float h = radius * 0.7071067812f;
		float zero = 0.0f;

		float vert[18] =
		{
			-radius, zero,
			-h, h,
			zero, zero,
			zero, radius,
			h, h,
			radius, zero,
			h, -h,
			zero, -radius,
			-h, -h
		};
		
		return vert;
	}

	unsigned int* GenCircleIndex()
	{
		unsigned int ind[24] =
		{
			0, 1, 2,
			1, 3, 2,
			3, 4, 2,
			4, 5, 2,
			5, 6, 2,
			6, 7, 2,
			7, 8, 2,
			8, 0, 2
		};

		return ind;
	}
}