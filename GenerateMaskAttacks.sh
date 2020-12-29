#!/bin/bash

g++ MaskAttacks/main.cpp -o MaskAttacks/main
MaskAttacks/main rook       > "engine/inc/MaskRookAttacks.hpp"
MaskAttacks/main knight     > "engine/inc/MaskKnightAttacks.hpp"
MaskAttacks/main beshop     > "engine/inc/MaskBeshopAttacks.hpp"
MaskAttacks/main queen      > "engine/inc/MaskQueenAttacks.hpp"
MaskAttacks/main king       > "engine/inc/MaskKingAttacks.hpp"
MaskAttacks/main white_pawn > "engine/inc/MaskWhitePawnAttacks.hpp"
MaskAttacks/main black_pawn > "engine/inc/MaskBlackPawnAttacks.hpp"
