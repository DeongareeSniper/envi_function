#include "../include/SpectralIndices.h"
#include <vector>
#include <algorithm>
using namespace std;

void bai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int red_num, nir_num;
    red_num = find_central_band(value_array_of_all_band, z, RED);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = burn_area_index(raw_data[i][j][red_num], raw_data[i][j][nir_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nbr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int swir2_num, nir_num;
    swir2_num = find_central_band(value_array_of_all_band, z, SWIR2);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_burn_ratio(raw_data[i][j][swir2_num], raw_data[i][j][nir_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
////////////////////////////////////////////////////////////////
void nbrt1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int swir2_num, nir_num, thermal_num;
    swir2_num = find_central_band(value_array_of_all_band, z, SWIR2);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    thermal_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_burn_ratio_thermal_1(raw_data[i][j][swir2_num], raw_data[i][j][nir_num], raw_data[i][j][thermal_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
////////////////////////////////////////////////////////////////
void cmr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int swir1_num, swir2_num;
    swir1_num = find_central_band(value_array_of_all_band, z, SWIR1);
    swir2_num = find_central_band(value_array_of_all_band, z, SWIR2);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = clay_minerals_ratio(raw_data[i][j][swir1_num], raw_data[i][j][swir2_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void fmr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int swir1_num, nir_num;
    swir1_num = find_central_band(value_array_of_all_band, z, SWIR1);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = ferrous_minerals_ratio(raw_data[i][j][swir1_num], raw_data[i][j][nir_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ior(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int red_num, blue_num;
    red_num = find_central_band(value_array_of_all_band, z, RED);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = iron_oxide_ratio(raw_data[i][j][red_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_ii(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int green_num, yellow_num, blue_num;
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    yellow_num = find_central_band(value_array_of_all_band, z, YELLOW);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldview_new_iron_index(raw_data[i][j][green_num], raw_data[i][j][yellow_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_si(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int green_num, yellow_num;
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    yellow_num = find_central_band(value_array_of_all_band, z, YELLOW);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldview_soil_index(raw_data[i][j][green_num], raw_data[i][j][yellow_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mndwi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int green_num, swir1_num;
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    swir1_num = find_central_band(value_array_of_all_band, z, SWIR1);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_normalized_difference_water_index(raw_data[i][j][green_num], raw_data[i][j][swir1_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndbi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int swir1_num, nir_num;
    swir1_num = find_central_band(value_array_of_all_band, z, SWIR1);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_built_up_index(raw_data[i][j][swir1_num], raw_data[i][j][nir_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndmi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p795_num, p990_num;
    p795_num = find_central_band(value_array_of_all_band, z, 795);
    p990_num = find_central_band(value_array_of_all_band, z, 990);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_mud_index(raw_data[i][j][p795_num], raw_data[i][j][p990_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndsi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int green_num, nir_num;
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_snow_index(raw_data[i][j][green_num], raw_data[i][j][nir_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_bi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int coastal_num, red_edge_num;
    coastal_num = find_central_band(value_array_of_all_band, z, Coastal);
    red_edge_num = find_central_band(value_array_of_all_band, z, Red_Edge);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldview_built_up_index(raw_data[i][j][coastal_num], raw_data[i][j][red_edge_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_nhfd(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int coastal_num, red_edge_num;
    coastal_num = find_central_band(value_array_of_all_band, z, Coastal);
    red_edge_num = find_central_band(value_array_of_all_band, z, Red_Edge);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldView_non_homogeneous_feature_difference(raw_data[i][j][red_edge_num], raw_data[i][j][coastal_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_wi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int coastal_num, nir2_num;
    coastal_num = find_central_band(value_array_of_all_band, z, Coastal);
    nir2_num = find_central_band(value_array_of_all_band, z, NIR2);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldview_water_index(raw_data[i][j][coastal_num], raw_data[i][j][nir2_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void arvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = atmospherically_resistant_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void dvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void evi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = enhanced_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gemi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = global_environmental_monitoring_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num, green_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = green_atmospherically_resistant_index(raw_data[i][j][nir_num], raw_data[i][j][red_num], raw_data[i][j][green_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    green_num = find_central_band(value_array_of_all_band, z, GREEN);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = green_difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][green_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gndvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    green_num = find_central_band(value_array_of_all_band, z, GREEN);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = green_normalized_difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][green_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void grvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    green_num = find_central_band(value_array_of_all_band, z, GREEN);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = green_ratio_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][green_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
//----------------------------------------------------------------
void gvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
}
//----------------------------------------------------------------
void ipvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = infrared_percentage_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void lai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = leaf_area_index(raw_data[i][j][nir_num], raw_data[i][j][red_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mnli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_non_linear_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void msr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_simple_ratio(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = non_linear_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int red_num, nir_num;
    red_num = find_central_band(value_array_of_all_band, z, RED);
    nir_num = find_central_band(value_array_of_all_band, z, NIR);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void osavi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = optimized_soil_adjusted_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = renormalized_difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void savi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = soil_adjusted_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = simple_ratio(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sgi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int a, b, c, d, n, m;
    float sgi;
    c = 0;
    d = 0;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; k++)
            {
                a = value_array_of_all_band[k];
                if (a >= 500 && a < 600)
                {
                    c += raw_data[i][j][z]; // 绿光
                    n++;
                }
                sgi = (float)c / (float)n;
                result[i][j] = transform_to_six_decimal_places(sgi);
            }
        }
    }
}
void tdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, z, NIR);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = Transformed_difference_vegetation_index(raw_data[i][j][nir_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int red_num, green_num, blue_num;
    green_num = find_central_band(value_array_of_all_band, z, GREEN);
    red_num = find_central_band(value_array_of_all_band, z, RED);
    blue_num = find_central_band(value_array_of_all_band, z, BLUE);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = visible_atmospherically_resistant_index(raw_data[i][j][red_num], raw_data[i][j][green_num], raw_data[i][j][blue_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_vi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int nir2_num, red_num;
    nir2_num = find_central_band(value_array_of_all_band, z, NIR2);
    red_num = find_central_band(value_array_of_all_band, z, RED);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = worldview_improved_vegetative_index(raw_data[i][j][nir2_num], raw_data[i][j][red_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mcari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p700_num = find_central_band(value_array_of_all_band, z, 700);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_chlorophyll_absorption_ratio_index(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p700_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mcari2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p800_num = find_central_band(value_array_of_all_band, z, 800);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_chlorophyll_absorption_ratio_index_improved(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p800_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mrendvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p445_num, p705_num, p750_num;
    p445_num = find_central_band(value_array_of_all_band, z, 445);
    p705_num = find_central_band(value_array_of_all_band, z, 705);
    p750_num = find_central_band(value_array_of_all_band, z, 750);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_red_edge_normalized_difference_vegetation_index(raw_data[i][j][p445_num], raw_data[i][j][p705_num], raw_data[i][j][p750_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mresr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p445_num, p705_num, p750_num;
    p445_num = find_central_band(value_array_of_all_band, z, 445);
    p705_num = find_central_band(value_array_of_all_band, z, 705);
    p750_num = find_central_band(value_array_of_all_band, z, 750);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_red_edge_simple_ratio(raw_data[i][j][p445_num], raw_data[i][j][p705_num], raw_data[i][j][p750_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mtvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p800_num = find_central_band(value_array_of_all_band, z, 800);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_triangular_vegetation_index(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p800_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mtvi2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p800_num = find_central_band(value_array_of_all_band, z, 800);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = modified_triangular_vegetation_index_improved(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p800_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rendvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p705_num, p750_num;
    p705_num = find_central_band(value_array_of_all_band, z, 705);
    p750_num = find_central_band(value_array_of_all_band, z, 750);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = red_edge_normalized_difference_vegetation_index(raw_data[i][j][p705_num], raw_data[i][j][p750_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}

//----------------------------------------------------------------
void repi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    // int a;
    // float dx, dy;
    // vector<float> reflectances;
    // vector<float> wavelengths;
    // vector<float> derivatives(wavelengths.size() - 1);
    // for (int i = 0; i < x; ++i)
    // {
    //     for (int j = 0; j < y; ++j)
    //     {
    //         for (int k = 0; k < z; ++k)
    //         {
    //             a = value_array_of_all_band[k];
    //             if (a >= 690 && a <= 740)
    //             {
    //                 reflectances.push_back((float)raw_data[i][j][k]);
    //                 wavelengths.push_back(a);
    //             }
    //         }
    //         for (int b = 0; b < wavelengths.size() - 1; ++b)
    //         {
    //             dx = wavelengths[b + 1] - wavelengths[b];
    //             dy = reflectances[b + 1] - reflectances[b];
    //             derivatives[b] = dy / dx;
    //         }
    //         auto maxIt = max_element(derivatives.begin(), derivatives.end());
    //         size_t maxIndex = distance(derivatives.begin(), maxIt);
    //         result[i][j] = (wavelengths[maxIndex] + wavelengths[maxIndex + 1]) / 2.0;
    //     }
    // }
}
//----------------------------------------------------------------

void tcari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p700_num = find_central_band(value_array_of_all_band, z, 700);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = transformed_chlorophyll_absorption_reflectance_index(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p700_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void tvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p670_num, p750_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p670_num = find_central_band(value_array_of_all_band, z, 670);
    p750_num = find_central_band(value_array_of_all_band, z, 750);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = triangular_vegetation_index(raw_data[i][j][p550_num], raw_data[i][j][p670_num], raw_data[i][j][p750_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vrei1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p720_num, p740_num;
    p720_num = find_central_band(value_array_of_all_band, z, 720);
    p740_num = find_central_band(value_array_of_all_band, z, 740);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = vogelmann_red_edge_index_1(raw_data[i][j][p720_num], raw_data[i][j][p740_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vrei2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p715_num, p726_num, p734_num, p747_num;
    p715_num = find_central_band(value_array_of_all_band, z, 715);
    p726_num = find_central_band(value_array_of_all_band, z, 726);
    p734_num = find_central_band(value_array_of_all_band, z, 734);
    p747_num = find_central_band(value_array_of_all_band, z, 747);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = vogelmann_red_edge_index_2(raw_data[i][j][p715_num], raw_data[i][j][p726_num], raw_data[i][j][p734_num], raw_data[i][j][p747_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndni(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p1510_num, p1680_num;
    p1510_num = find_central_band(value_array_of_all_band, z, 1510);
    p1680_num = find_central_band(value_array_of_all_band, z, 1680);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_nitrogen_index(raw_data[i][j][p1510_num], raw_data[i][j][p1680_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void msi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p1599_num, p819_num;
    p1599_num = find_central_band(value_array_of_all_band, z, 1599);
    p819_num = find_central_band(value_array_of_all_band, z, 819);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = moisture_stress_index(raw_data[i][j][p1599_num], raw_data[i][j][p819_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndii(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p819_num, p1649_num;
    p819_num = find_central_band(value_array_of_all_band, z, 819);
    p1649_num = find_central_band(value_array_of_all_band, z, 1649);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_infrared_index(raw_data[i][j][p819_num], raw_data[i][j][p1649_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndwi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p857_num, p1241_num;
    p857_num = find_central_band(value_array_of_all_band, z, 857);
    p1241_num = find_central_band(value_array_of_all_band, z, 1241);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_water_index(raw_data[i][j][p857_num], raw_data[i][j][p1241_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nmdi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p860_num, p1640_num, p2130_num;
    p860_num = find_central_band(value_array_of_all_band, z, 860);
    p1640_num = find_central_band(value_array_of_all_band, z, 1640);
    p2130_num = find_central_band(value_array_of_all_band, z, 2130);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_multi_band_drought_index(raw_data[i][j][p860_num], raw_data[i][j][p1640_num], raw_data[i][j][p2130_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wbi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p900_num, p970_num;
    p900_num = find_central_band(value_array_of_all_band, z, 900);
    p970_num = find_central_band(value_array_of_all_band, z, 970);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = water_band_index(raw_data[i][j][p900_num], raw_data[i][j][p970_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p1680_num, p1754_num;
    p1680_num = find_central_band(value_array_of_all_band, z, 1680);
    p1754_num = find_central_band(value_array_of_all_band, z, 1754);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = normalized_difference_lignin_index(raw_data[i][j][p1680_num], raw_data[i][j][p1754_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p2000_num, p2100_num, p2200_num;
    p2000_num = find_central_band(value_array_of_all_band, z, 2000);
    p2100_num = find_central_band(value_array_of_all_band, z, 2100);
    p2200_num = find_central_band(value_array_of_all_band, z, 2200);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = cellulose_absorption_index(raw_data[i][j][p2000_num], raw_data[i][j][p2100_num], raw_data[i][j][p2200_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void psri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p500_num, p680_num, p750_num;
    p500_num = find_central_band(value_array_of_all_band, z, 500);
    p680_num = find_central_band(value_array_of_all_band, z, 680);
    p750_num = find_central_band(value_array_of_all_band, z, 750);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = plant_senescence_reflectance_index(raw_data[i][j][p500_num], raw_data[i][j][p680_num], raw_data[i][j][p750_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ari1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p700_num = find_central_band(value_array_of_all_band, z, 700);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = anthocyanin_reflectance_index_1(raw_data[i][j][p550_num], raw_data[i][j][p700_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ari2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p550_num, p700_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, z, 550);
    p700_num = find_central_band(value_array_of_all_band, z, 700);
    p800_num = find_central_band(value_array_of_all_band, z, 800);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = anthocyanin_reflectance_index_2(raw_data[i][j][p550_num], raw_data[i][j][p700_num], raw_data[i][j][p800_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cri1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p510_num, p550_num;
    p510_num = find_central_band(value_array_of_all_band, z, 510);
    p550_num = find_central_band(value_array_of_all_band, z, 550);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = carotenoid_reflectance_index_1(raw_data[i][j][p510_num], raw_data[i][j][p550_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cri2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p510_num, p700_num;
    p510_num = find_central_band(value_array_of_all_band, z, 510);
    p700_num = find_central_band(value_array_of_all_band, z, 700);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = carotenoid_reflectance_index_2(raw_data[i][j][p510_num], raw_data[i][j][p700_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void pri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p531_num, p570_num;
    p531_num = find_central_band(value_array_of_all_band, z, 531);
    p570_num = find_central_band(value_array_of_all_band, z, 570);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = photochemical_reflectance_index(raw_data[i][j][p531_num], raw_data[i][j][p570_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sipi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int p445_num, p680_num, p800_num;
    p445_num = find_central_band(value_array_of_all_band, z, 445);
    p680_num = find_central_band(value_array_of_all_band, z, 680);
    p800_num = find_central_band(value_array_of_all_band, z, 800);

    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            float a = structure_insensitive_pigment_index(raw_data[i][j][p445_num], raw_data[i][j][p680_num], raw_data[i][j][p800_num]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rgri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result)
{
    int a, b, c, d, n, m;
    float rgri;
    c = 0;
    d = 0;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 0; j < y; ++j)
        {
            for (int k = 0; k < z; k++)
            {
                a = value_array_of_all_band[k];
                if (a >= 600 && a < 700)
                {
                    c += raw_data[i][j][z]; // 红光
                    n++;
                }
                if (a >= 500 && a < 600)
                {
                    d += raw_data[i][j][z]; // 绿光
                    m++;
                }
                rgri = ((float)c / (float)n) / ((float)d / (float)m);
                result[i][j] = transform_to_six_decimal_places(rgri);
            }
        }
    }
}