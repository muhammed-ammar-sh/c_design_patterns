#include "map.h"

void Map_Init(map_t *map, point_t *points_array, size_t max_points_count)
{
	if (map && points_array)
	{
		map->points = points_array;
		map->max_points_count = max_points_count;
		map->points_count = 0;
		map->printer = NULL;
	}
}

///@brief Sets the printing strategy
void Map_SetPrinter(map_t *map, map_printer_t printer)
{
	if (map && printer)
	{
		map->printer = printer;
	}
}

///@brief invokes an already set printing strategy
void Map_Print(map_t *map)
{
	if (map && map->printer)
	{
		map->printer(map->points, map->points_count);
	}
}

void Map_AddPoint(map_t *map, point_t point)
{
	if (map && map->points_count < map->max_points_count)
	{
		map->points[map->points_count++] = point;
	}
}