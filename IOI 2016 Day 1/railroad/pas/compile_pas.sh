#!/bin/bash

problem=railroad

fpc -XS -O2 -o$problem grader.pas
