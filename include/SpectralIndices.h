#include "../include/SpectralIndices_math.h"
using namespace std;

void bai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void nbr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void nbrt1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void cmr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void fmr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ior(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_ii(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_si(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mndwi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndbi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndmi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndsi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_bi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_nhfd(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_wi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void arvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void dvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void evi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void gemi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void gari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void gdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void gndvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void grvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void gvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ipvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void lai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mnli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void msr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void nli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void osavi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void rdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void savi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void sr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void sgi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void tdvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void vari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wv_vi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mcari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mcari2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mrendvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mresr(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mtvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void mtvi2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void rendvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void repi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void tcari(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void tvi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void vrei1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void vrei2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndni(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void msi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndii(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndwi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void nmdi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void wbi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ndli(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void cai(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void psri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ari1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void ari2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void cri1(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void cri2(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void pri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void sipi(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);
void rgri(int ***raw_data, int x, int y, int z, double *value_array_of_all_band, double **result);









