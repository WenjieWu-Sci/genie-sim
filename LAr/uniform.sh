#!/bin/bash

## nue
#gevgen -r 1 -n 100000 -p 12 -t 1000180400 -e 0,10 -f nu_ar40_uniform_flux.root,nueflux --seed 49 --cross-sections /cvmfs/nova.opensciencegrid.org/externals/genie_xsec/v3_04_00/NULL/AR2320i00000-k250-e1000/data/gxspl-NUsmall.xml --tune AR23_20i_00_000 &> nue_ar40_e_0-10GeV.log &

## numu
gevgen -r 1 -n 100000 -p 14 -t 1000180400 -e 0,10 -f nu_ar40_uniform_flux.root,numuflux --seed 49 --cross-sections /cvmfs/nova.opensciencegrid.org/externals/genie_xsec/v3_04_00/NULL/AR2320i00000-k250-e1000/data/gxspl-NUsmall.xml --tune AR23_20i_00_000 > /dev/null 2>&1 &

