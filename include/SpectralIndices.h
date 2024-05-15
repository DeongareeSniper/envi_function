#include "../include/SpectralIndices_math.h"
using namespace std;
void bai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void nbr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void nbrt1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void cmr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void fmr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ior(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_ii(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_si(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mndwi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndbi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndmi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndsi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_bi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_nhfd(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_wi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void arvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void dvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void evi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void gemi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void gari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void gdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void gndvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void grvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void gvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ipvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void lai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mnli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void msr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void nli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void osavi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void rdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void savi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void sr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void sgi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void tdvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void vari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wv_vi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mcari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mcari2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mrendvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mresr(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mtvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void mtvi2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void rendvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void repi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void tcari(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void tvi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void vrei1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void vrei2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndni(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void msi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndii(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndwi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void nmdi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void wbi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ndli(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void cai(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void psri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ari1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void ari2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void cri1(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void cri2(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void pri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void sipi(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);
void rgri(int ***raw_data, int x, int y, int z, float *value_array_of_all_band, float **result);









