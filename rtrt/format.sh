#!/bin/bash
astyle -T4 -A1 -L -w -C -S -K -N -M80 -m0 -Y -f -p -xd -k3 -U -H -z2 -j -y -n -r "*.cpp"
astyle -T4 -A1 -L -w -C -S -K -N -M80 -m0 -Y -f -p -xd -k3 -U -H -z2 -j -y -n -r "*.h"

