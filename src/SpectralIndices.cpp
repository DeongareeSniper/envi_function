#include "../include/SpectralIndices.h"
#include <vector>
#include <algorithm>
using namespace std;

void bai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int red_num, nir_num;
    red_num = find_central_band(value_array_of_all_band, x, RED);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = burn_area_index(raw_data[red_num][i][j], raw_data[nir_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nbr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int swir2_num, nir_num;
    swir2_num = find_central_band(value_array_of_all_band, x, SWIR2);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_burn_ratio(raw_data[swir2_num][i][j], raw_data[nir_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
////////////////////////////////////////////////////////////////
void nbrt1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int swir2_num, nir_num, thermal_num;
    swir2_num = find_central_band(value_array_of_all_band, x, SWIR2);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    thermal_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_burn_ratio_thermal_1(raw_data[swir2_num][i][j], raw_data[nir_num][i][j], raw_data[thermal_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
////////////////////////////////////////////////////////////////
void cmr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int swir1_num, swir2_num;
    swir1_num = find_central_band(value_array_of_all_band, x, SWIR1);
    swir2_num = find_central_band(value_array_of_all_band, x, SWIR2);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = clay_minerals_ratio(raw_data[swir1_num][i][j], raw_data[swir2_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void fmr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int swir1_num, nir_num;
    swir1_num = find_central_band(value_array_of_all_band, x, SWIR1);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = ferrous_minerals_ratio(raw_data[swir1_num][i][j], raw_data[nir_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ior(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int red_num, blue_num;
    red_num = find_central_band(value_array_of_all_band, x, RED);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = iron_oxide_ratio(raw_data[red_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_ii(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int green_num, yellow_num, blue_num;
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    yellow_num = find_central_band(value_array_of_all_band, x, YELLOW);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldview_new_iron_index(raw_data[green_num][i][j], raw_data[yellow_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_si(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int green_num, yellow_num;
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    yellow_num = find_central_band(value_array_of_all_band, x, YELLOW);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldview_soil_index(raw_data[green_num][i][j], raw_data[yellow_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mndwi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int green_num, swir1_num;
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    swir1_num = find_central_band(value_array_of_all_band, x, SWIR1);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_normalized_difference_water_index(raw_data[green_num][i][j], raw_data[swir1_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndbi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int swir1_num, nir_num;
    swir1_num = find_central_band(value_array_of_all_band, x, SWIR1);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_built_up_index(raw_data[swir1_num][i][j], raw_data[nir_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndmi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p795_num, p990_num;
    p795_num = find_central_band(value_array_of_all_band, x, 795);
    p990_num = find_central_band(value_array_of_all_band, x, 990);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_mud_index(raw_data[p795_num][i][j], raw_data[p990_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndsi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int green_num, nir_num;
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_snow_index(raw_data[green_num][i][j], raw_data[nir_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_bi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int coastal_num, red_edge_num;
    coastal_num = find_central_band(value_array_of_all_band, x, Coastal);
    red_edge_num = find_central_band(value_array_of_all_band, x, Red_Edge);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldview_built_up_index(raw_data[coastal_num][i][j], raw_data[red_edge_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_nhfd(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int coastal_num, red_edge_num;
    coastal_num = find_central_band(value_array_of_all_band, x, Coastal);
    red_edge_num = find_central_band(value_array_of_all_band, x, Red_Edge);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldView_non_homogeneous_feature_difference(raw_data[red_edge_num][i][j], raw_data[coastal_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_wi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int coastal_num, nir2_num;
    coastal_num = find_central_band(value_array_of_all_band, x, Coastal);
    nir2_num = find_central_band(value_array_of_all_band, x, NIR2);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldview_water_index(raw_data[coastal_num][i][j], raw_data[nir2_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void arvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = atmospherically_resistant_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void dvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = difference_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void evi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = enhanced_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gemi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = global_environmental_monitoring_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num, green_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = green_atmospherically_resistant_index(raw_data[nir_num][i][j], raw_data[red_num][i][j], raw_data[green_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    green_num = find_central_band(value_array_of_all_band, x, GREEN);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = green_difference_vegetation_index(raw_data[nir_num][i][j], raw_data[green_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void gndvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    green_num = find_central_band(value_array_of_all_band, x, GREEN);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = green_normalized_difference_vegetation_index(raw_data[nir_num][i][j], raw_data[green_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void grvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, green_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    green_num = find_central_band(value_array_of_all_band, x, GREEN);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = green_ratio_vegetation_index(raw_data[nir_num][i][j], raw_data[green_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
//----------------------------------------------------------------
void gvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
}
//----------------------------------------------------------------
void ipvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = infrared_percentage_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void lai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num, blue_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = leaf_area_index(raw_data[nir_num][i][j], raw_data[red_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mnli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_non_linear_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void msr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_simple_ratio(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = non_linear_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int red_num, nir_num;
    red_num = find_central_band(value_array_of_all_band, x, RED);
    nir_num = find_central_band(value_array_of_all_band, x, NIR);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void osavi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = optimized_soil_adjusted_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = renormalized_difference_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void savi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = soil_adjusted_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = simple_ratio(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sgi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int a, b, c, d, n, m;
    double sgi;
    c = 0;
    d = 0;
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            for (int k = 0; k < x; k++)
            {
                a = value_array_of_all_band[k];
                if (a >= 500 && a < 600)
                {
                    c += raw_data[i][j][x]; // 绿光
                    n++;
                }
                sgi = (double)c / (double)n;
                result[i][j] = transform_to_six_decimal_places(sgi);
            }
        }
    }
}
void tdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir_num, red_num;
    nir_num = find_central_band(value_array_of_all_band, x, NIR);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = Transformed_difference_vegetation_index(raw_data[nir_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int red_num, green_num, blue_num;
    green_num = find_central_band(value_array_of_all_band, x, GREEN);
    red_num = find_central_band(value_array_of_all_band, x, RED);
    blue_num = find_central_band(value_array_of_all_band, x, BLUE);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = visible_atmospherically_resistant_index(raw_data[red_num][i][j], raw_data[green_num][i][j], raw_data[blue_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wv_vi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int nir2_num, red_num;
    nir2_num = find_central_band(value_array_of_all_band, x, NIR2);
    red_num = find_central_band(value_array_of_all_band, x, RED);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = worldview_improved_vegetative_index(raw_data[nir2_num][i][j], raw_data[red_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mcari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p700_num = find_central_band(value_array_of_all_band, x, 700);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_chlorophyll_absorption_ratio_index(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p700_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mcari2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p800_num = find_central_band(value_array_of_all_band, x, 800);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_chlorophyll_absorption_ratio_index_improved(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p800_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mrendvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p445_num, p705_num, p750_num;
    p445_num = find_central_band(value_array_of_all_band, x, 445);
    p705_num = find_central_band(value_array_of_all_band, x, 705);
    p750_num = find_central_band(value_array_of_all_band, x, 750);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_red_edge_normalized_difference_vegetation_index(raw_data[p445_num][i][j], raw_data[p705_num][i][j], raw_data[p750_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mresr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p445_num, p705_num, p750_num;
    p445_num = find_central_band(value_array_of_all_band, x, 445);
    p705_num = find_central_band(value_array_of_all_band, x, 705);
    p750_num = find_central_band(value_array_of_all_band, x, 750);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_red_edge_simple_ratio(raw_data[p445_num][i][j], raw_data[p705_num][i][j], raw_data[p750_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mtvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p800_num = find_central_band(value_array_of_all_band, x, 800);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_triangular_vegetation_index(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p800_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void mtvi2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p800_num = find_central_band(value_array_of_all_band, x, 800);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = modified_triangular_vegetation_index_improved(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p800_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rendvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p705_num, p750_num;
    p705_num = find_central_band(value_array_of_all_band, x, 705);
    p750_num = find_central_band(value_array_of_all_band, x, 750);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = red_edge_normalized_difference_vegetation_index(raw_data[p705_num][i][j], raw_data[p750_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}

//----------------------------------------------------------------
void repi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    double a;
    double dx, dy;
    vector<double> reflectances;
    vector<double> wavelengths;
    vector<double> derivatives(wavelengths.size() - 1);
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            for (int k = 0; k < x; ++k)
            {
                a = value_array_of_all_band[k];
                if (a >= 690 && a <= 740)
                {
                    reflectances.push_back((double)raw_data[i][j][k]);
                    wavelengths.push_back(a);
                }
            }
            for (int b = 0; b < wavelengths.size() - 1; ++b)
            {
                dx = wavelengths[b + 1] - wavelengths[b];
                dy = reflectances[b + 1] - reflectances[b];
                derivatives[b] = dy / dx;
            }
            auto maxIt = max_element(derivatives.begin(), derivatives.end());
            size_t maxIndex = distance(derivatives.begin(), maxIt);
            result[i][j] = (wavelengths[maxIndex] + wavelengths[maxIndex + 1]) / 2.0;
        }
    }
}
//----------------------------------------------------------------

void tcari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p700_num = find_central_band(value_array_of_all_band, x, 700);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = transformed_chlorophyll_absorption_reflectance_index(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p700_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void tvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p670_num, p750_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p670_num = find_central_band(value_array_of_all_band, x, 670);
    p750_num = find_central_band(value_array_of_all_band, x, 750);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = triangular_vegetation_index(raw_data[p550_num][i][j], raw_data[p670_num][i][j], raw_data[p750_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vrei1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p720_num, p740_num;
    p720_num = find_central_band(value_array_of_all_band, x, 720);
    p740_num = find_central_band(value_array_of_all_band, x, 740);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = vogelmann_red_edge_index_1(raw_data[p720_num][i][j], raw_data[p740_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void vrei2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p715_num, p726_num, p734_num, p747_num;
    p715_num = find_central_band(value_array_of_all_band, x, 715);
    p726_num = find_central_band(value_array_of_all_band, x, 726);
    p734_num = find_central_band(value_array_of_all_band, x, 734);
    p747_num = find_central_band(value_array_of_all_band, x, 747);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = vogelmann_red_edge_index_2(raw_data[p715_num][i][j], raw_data[p726_num][i][j], raw_data[p734_num][i][j], raw_data[p747_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndni(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p1510_num, p1680_num;
    p1510_num = find_central_band(value_array_of_all_band, x, 1510);
    p1680_num = find_central_band(value_array_of_all_band, x, 1680);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_nitrogen_index(raw_data[p1510_num][i][j], raw_data[p1680_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void msi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p1599_num, p819_num;
    p1599_num = find_central_band(value_array_of_all_band, x, 1599);
    p819_num = find_central_band(value_array_of_all_band, x, 819);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = moisture_stress_index(raw_data[p1599_num][i][j], raw_data[p819_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndii(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p819_num, p1649_num;
    p819_num = find_central_band(value_array_of_all_band, x, 819);
    p1649_num = find_central_band(value_array_of_all_band, x, 1649);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_infrared_index(raw_data[p819_num][i][j], raw_data[p1649_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndwi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p857_num, p1241_num;
    p857_num = find_central_band(value_array_of_all_band, x, 857);
    p1241_num = find_central_band(value_array_of_all_band, x, 1241);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_water_index(raw_data[p857_num][i][j], raw_data[p1241_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void nmdi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p860_num, p1640_num, p2130_num;
    p860_num = find_central_band(value_array_of_all_band, x, 860);
    p1640_num = find_central_band(value_array_of_all_band, x, 1640);
    p2130_num = find_central_band(value_array_of_all_band, x, 2130);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_multi_band_drought_index(raw_data[p860_num][i][j], raw_data[p1640_num][i][j], raw_data[p2130_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void wbi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p900_num, p970_num;
    p900_num = find_central_band(value_array_of_all_band, x, 900);
    p970_num = find_central_band(value_array_of_all_band, x, 970);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = water_band_index(raw_data[p900_num][i][j], raw_data[p970_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ndli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p1680_num, p1754_num;
    p1680_num = find_central_band(value_array_of_all_band, x, 1680);
    p1754_num = find_central_band(value_array_of_all_band, x, 1754);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = normalized_difference_lignin_index(raw_data[p1680_num][i][j], raw_data[p1754_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p2000_num, p2100_num, p2200_num;
    p2000_num = find_central_band(value_array_of_all_band, x, 2000);
    p2100_num = find_central_band(value_array_of_all_band, x, 2100);
    p2200_num = find_central_band(value_array_of_all_band, x, 2200);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = cellulose_absorption_index(raw_data[p2000_num][i][j], raw_data[p2100_num][i][j], raw_data[p2200_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void psri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p500_num, p680_num, p750_num;
    p500_num = find_central_band(value_array_of_all_band, x, 500);
    p680_num = find_central_band(value_array_of_all_band, x, 680);
    p750_num = find_central_band(value_array_of_all_band, x, 750);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = plant_senescence_reflectance_index(raw_data[p500_num][i][j], raw_data[p680_num][i][j], raw_data[p750_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ari1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p700_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p700_num = find_central_band(value_array_of_all_band, x, 700);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = anthocyanin_reflectance_index_1(raw_data[p550_num][i][j], raw_data[p700_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void ari2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p550_num, p700_num, p800_num;
    p550_num = find_central_band(value_array_of_all_band, x, 550);
    p700_num = find_central_band(value_array_of_all_band, x, 700);
    p800_num = find_central_band(value_array_of_all_band, x, 800);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = anthocyanin_reflectance_index_2(raw_data[p550_num][i][j], raw_data[p700_num][i][j], raw_data[p800_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cri1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p510_num, p550_num;
    p510_num = find_central_band(value_array_of_all_band, x, 510);
    p550_num = find_central_band(value_array_of_all_band, x, 550);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = carotenoid_reflectance_index_1(raw_data[p510_num][i][j], raw_data[p550_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void cri2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p510_num, p700_num;
    p510_num = find_central_band(value_array_of_all_band, x, 510);
    p700_num = find_central_band(value_array_of_all_band, x, 700);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = carotenoid_reflectance_index_2(raw_data[p510_num][i][j], raw_data[p700_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void pri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p531_num, p570_num;
    p531_num = find_central_band(value_array_of_all_band, x, 531);
    p570_num = find_central_band(value_array_of_all_band, x, 570);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = photochemical_reflectance_index(raw_data[p531_num][i][j], raw_data[p570_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void sipi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int p445_num, p680_num, p800_num;
    p445_num = find_central_band(value_array_of_all_band, x, 445);
    p680_num = find_central_band(value_array_of_all_band, x, 680);
    p800_num = find_central_band(value_array_of_all_band, x, 800);

    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            double a = structure_insensitive_pigment_index(raw_data[p445_num][i][j], raw_data[p680_num][i][j], raw_data[p800_num][i][j]);
            result[i][j] = transform_to_six_decimal_places(a);
        }
    }
}
void rgri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result)
{
    int a, b, c, d, n, m;
    double rgri;
    c = 0;
    d = 0;
    for (int i = 0; i < y; ++i)
    {
        for (int j = 0; j < z; ++j)
        {
            for (int k = 0; k < x; k++)
            {
                a = value_array_of_all_band[k];
                if (a >= 600 && a < 700)
                {
                    c += raw_data[i][j][x]; // 红光
                    n++;
                }
                if (a >= 500 && a < 600)
                {
                    d += raw_data[i][j][x]; // 绿光
                    m++;
                }
                rgri = ((double)c / (double)n) / ((double)d / (double)m);
                result[i][j] = transform_to_six_decimal_places(rgri);
            }
        }
    }
}