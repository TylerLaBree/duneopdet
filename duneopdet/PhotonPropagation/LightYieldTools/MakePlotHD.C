// Tyler LaBree
// Northern Illinois University

#include "PhotonLibrary.h"
#include "LightYieldMap.h"
#include "DepthPlot.h"

void MakePlotHD() {
  Double_t simulatedBoundsInM[3][2] = { // For horizontal drift
    { 0.    ,  3.79  },
    {-6.50  ,  6.50  },
    { 0.    , 14.40  }
  };
  Double_t fiducialBoundsInM[3][2] = { // For horizontal drift
    { 0.    ,  3.79  },
    {-6.50  ,  6.50  },
    { 0.052 , 14.348 }
  };
  Int_t dims[3] = {75,180,200};
  PhotonLibrary* lib = new PhotonLibrary(
    "/pnfs/dune/scratch/users/lpaulucc/dunehd1x2x6lib/lib_fd1hd_1x2x6.root"
    , dims
    , simulatedBoundsInM
    , fiducialBoundsInM);
  
  // Define depth ranges on which to average over to make light yield plots.
  Int_t centerSlice[2] = {95,97};
  //Int_t centerAvg[2] = {96,114};
  Int_t centerAvg[2] = {79,114};
  Int_t fullAvg[2] = {9,184};

  /* Make a light yield plot perpendicular to the z-dir, averaged over a
   * range, using the photon library made above.
   */
  LightYieldMap* lymap = new LightYieldMap(lib, 2, centerAvg);
  lymap->Draw();

  // Draw average and minimum light yield across detector depth.
  DrawDepthPlot(lib, fullAvg[0], fullAvg[1]);
}
