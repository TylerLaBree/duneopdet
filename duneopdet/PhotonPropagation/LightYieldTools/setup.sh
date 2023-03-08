#!/bin/bash
# Tyler LaBree
# Northern Illinois University

# Setup the latest versions of root and dune-plot-style
source /cvmfs/dune.opensciencegrid.org/products/dune/setup_dune.sh
setup root v6_22_08d -q e20:p392:prof
setup dune_plot_style v00_02

# Teach ROOT about the dune-plot-style include directory
export ROOT_INCLUDE_PATH=$DUNE_PLOT_STYLE_INC:$ROOT_INCLUDE_PATH
