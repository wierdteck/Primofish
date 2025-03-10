#include <iostream>
#include <cstring>
#include "constants.h"

#pragma region General constants

const int MOVE_STARTING = 0;
const int MOVE_TARGET = 1;
const int MOVE_PIECE = 2;
const int MOVE_TAG = 3;

const char* FEN_STARTING_POSITION = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1";

const unsigned long long WKS_EMPTY_BITBOARD = 6917529027641081856;
const unsigned long long WQS_EMPTY_BITBOARD = 1008806316530991104;
const unsigned long long BKS_EMPTY_BITBOARD = 96;
const unsigned long long BQS_EMPTY_BITBOARD = 14;

const unsigned long long MAX_ULONG = 18446744073709551615ULL;

const char SQ_CHAR_Y[65] =
{
    '8','8','8','8','8','8','8','8',
    '7','7','7','7','7','7','7','7',
    '6','6','6','6','6','6','6','6',
    '5','5','5','5','5','5','5','5',
    '4','4','4','4','4','4','4','4',
    '3','3','3','3','3','3','3','3',
    '2','2','2','2','2','2','2','2',
    '1','1','1','1','1','1','1','1','A'
};

const char SQ_CHAR_X[65] =
{
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h',
    'a','b','c','d','e','f','g','h','N'
};

const int WKS_CASTLE_RIGHTS = 0, WQS_CASTLE_RIGHTS = 1, BKS_CASTLE_RIGHTS = 2, BQS_CASTLE_RIGHTS = 3;
const int WP = 0, WN = 1, WB = 2, WR = 3, WQ = 4, WK = 5,
BP = 6, BN = 7, BB = 8, BR = 9, BQ = 10, BK = 11;

const int A8 = 0, B8 = 1, C8 = 2, D8 = 3, E8 = 4, F8 = 5, G8 = 6, H8 = 7,
A7 = 8, B7 = 9, C7 = 10, D7 = 11, E7 = 12, F7 = 13, G7 = 14, H7 = 15,
A6 = 16, B6 = 17, C6 = 18, D6 = 19, E6 = 20, F6 = 21, G6 = 22, H6 = 23,
A5 = 24, B5 = 25, C5 = 26, D5 = 27, E5 = 28, F5 = 29, G5 = 30, H5 = 31,
A4 = 32, B4 = 33, C4 = 34, D4 = 35, E4 = 36, F4 = 37, G4 = 38, H4 = 39,
A3 = 40, B3 = 41, C3 = 42, D3 = 43, E3 = 44, F3 = 45, G3 = 46, H3 = 47,
A2 = 48, B2 = 49, C2 = 50, D2 = 51, E2 = 52, F2 = 53, G2 = 54, H2 = 55,
A1 = 56, B1 = 57, C1 = 58, D1 = 59, E1 = 60, F1 = 61, G1 = 62, H1 = 63, NO_SQUARE = 64;

const unsigned long long RANK_1_BITBOARD = 18374686479671623680ULL;
const unsigned long long RANK_2_BITBOARD = 71776119061217280;
const unsigned long long RANK_3_BITBOARD = 280375465082880;
const unsigned long long RANK_4_BITBOARD = 1095216660480;
const unsigned long long RANK_5_BITBOARD = 4278190080;
const unsigned long long RANK_6_BITBOARD = 16711680;
const unsigned long long RANK_7_BITBOARD = 65280;
const unsigned long long RANK_8_BITBOARD = 255;

const int WHITE_START_INDEX = WP;
const int WHITE_END_INDEX = WK;
const int BLACK_START_INDEX = BP;
const int BLACK_END_INDEX = BK;

const int PINNED_SQUARE_INDEX = 0;
const int PINNING_PIECE_INDEX = 1;

const int TAG_NONE = 0, TAG_CAPTURE = 1, TAG_WHITEEP = 2, TAG_BLACKEP = 3, TAG_WCASTLEKS = 4, TAG_WCASTLEQS = 5, TAG_BCASTLEKS = 6, TAG_BCASTLEQS = 7,
TAG_BKnightPromotion = 8, TAG_BBishopPromotion = 9, TAG_BQueenPromotion = 10, TAG_BRookPromotion = 11,
TAG_WKnightPromotion = 12, TAG_WBishopPromotion = 13, TAG_WQueenPromotion = 14, TAG_WRookPromotion = 15,
TAG_BCaptureKnightPromotion = 16, TAG_BCaptureBishopPromotion = 17, TAG_BCaptureQueenPromotion = 18, TAG_BCaptureRookPromotion = 19,
TAG_WCaptureKnightPromotion = 20, TAG_WCaptureBishopPromotion = 21, TAG_WCaptureQueenPromotion = 22, TAG_WCaptureRookPromotion = 23,
TAG_DoublePawnWhite = 24, TAG_DoublePawnBlack = 25, TAG_CHECK = 26, TAG_CHECK_CAPTURE = 27;

const unsigned long long MAGIC = 285870213051386505;

const int DEBRUIJN64[64] =
{
   0, 47,  1, 56, 48, 27,  2, 60,
   57, 49, 41, 37, 28, 16,  3, 61,
   54, 58, 35, 52, 50, 42, 21, 44,
   38, 32, 29, 23, 17, 11,  4, 62,
   46, 55, 26, 59, 40, 36, 15, 53,
   34, 51, 20, 43, 31, 22, 10, 45,
   25, 39, 14, 33, 19, 30,  9, 24,
   13, 18,  8, 12,  7,  6,  5, 63
};

#pragma endregion

//equation: startingSquare = (DEBRUIJN64[MAGIC * (tempBitboard ^ (tempBitboard - 1)) >> 58]);

inline bool PieceIsWhite(const int piece)
{
    if (piece >= WP)
    {
        if (piece <= WK)
        {
            return true;
        }
    }
    return false;
}

inline int deleteAttacks(const unsigned long long tempPieceMoves) {
    return tempPieceMoves | (tempPieceMoves >> 8);
}

inline int BitscanForward(const unsigned long long tempBitboard)
{
    return (DEBRUIJN64[MAGIC * (tempBitboard ^ (tempBitboard - 1)) >> 58]);
}

inline unsigned long long GetRookAttacksFast(const int startingSquare, unsigned long long occupancy)
{
    occupancy &= ROOK_MASKS[startingSquare];
    occupancy *= ROOK_MAGIC_NUMBERS[startingSquare];
    occupancy >>= 64 - ROOK_REL_BITS[startingSquare];
    return ROOK_ATTACKS[startingSquare][occupancy];
}

inline unsigned long long  GetBishopAttacksFast(const int startingSquare, unsigned long long occupancy)
{
    occupancy &= BISHOP_MASKS[startingSquare];
    occupancy *= BISHOP_MAGIC_NUMBERS[startingSquare];
    occupancy >>= 64 - BISHOP_REL_BITS[startingSquare];
    return BISHOP_ATTACKS[startingSquare][occupancy];
}


unsigned long long* bitboardArray[12];
int* ep;
bool* castleRights[4];
bool* isWhite;

unsigned long long bitboard_array_global[12];
int ep_global;
bool castle_rights_global[4];
bool is_white_global;


inline bool Is_Square_Attacked_By_Black_Global(const int square, const unsigned long long occupancy)
{
    if ((bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[square]) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[BN] & KNIGHT_ATTACKS[square]) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[BK] & KING_ATTACKS[square]) != 0)
    {
        return true;
    }
    unsigned long long bishopAttacks = GetBishopAttacksFast(square, occupancy);
    if ((bitboard_array_global[BB] & bishopAttacks) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[BQ] & bishopAttacks) != 0)
    {
        return true;
    }
    unsigned long long rookAttacks = GetRookAttacksFast(square, occupancy);
    if ((bitboard_array_global[BR] & rookAttacks) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[BQ] & rookAttacks) != 0)
    {
        return true;
    }
    return false;
}

inline bool Is_Square_Attacked_By_White_Global(const int square, const unsigned long long occupancy)
{
    if ((bitboard_array_global[WP] & BLACK_PAWN_ATTACKS[square]) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[WN] & KNIGHT_ATTACKS[square]) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[WK] & KING_ATTACKS[square]) != 0)
    {
        return true;
    }
    unsigned long long bishopAttacks = GetBishopAttacksFast(square, occupancy);
    if ((bitboard_array_global[WB] & bishopAttacks) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[WQ] & bishopAttacks) != 0)
    {
        return true;
    }
    unsigned long long rookAttacks = GetRookAttacksFast(square, occupancy);
    if ((bitboard_array_global[WR] & rookAttacks) != 0)
    {
        return true;
    }
    if ((bitboard_array_global[WQ] & rookAttacks) != 0)
    {
        return true;
    }
    return false;
}


void CreateBoard()
{
    for (size_t i = 0; i < 12; ++i)
    {
        bitboardArray[i] = new unsigned long long;
    }
    ep = new int;
    isWhite = new bool;
    for (size_t i = 0; i < 4; ++i)
    {
        castleRights[i] = new bool;
    }
}


void CopyGlobalBoardGlobal()
{
    for (size_t i = 0; i < 12; ++i)
    {
        bitboard_array_global[i] = *bitboardArray[i];
    }
    for (size_t i = 0; i < 4; ++i)
    {
        castle_rights_global[i] = *castleRights[i];
    }
    ep_global = *ep;
    is_white_global = *isWhite;
}


void ResetBoardGlobal()
{
    *castleRights[0] = false;
    *castleRights[1] = false;
    *castleRights[2] = false;
    *castleRights[3] = false;

    for (size_t i = 0; i < 12; i++)
    {
        *bitboardArray[i] = 0;
    }
    *isWhite = true;
    *ep = NO_SQUARE;
}

const int PIECE_PHASE = 0;  const int SIDE_PHASE = 1; const int CASTLE_PHASE = 2; const int EP_PHASE = 3; const int FIFTY_MOVE_PHASE = 4; const int MOVE_COUNT_PHASE = 5;

void ParseFenGlobal(const char input[], const size_t startingIndex)
{
    ResetBoardGlobal();

    const size_t inputLength = strlen(input);
    if (startingIndex >= inputLength)
    {
        return;
    }
    if (startingIndex < 0)
    {
        return;
    }

    int currentPhase = PIECE_PHASE;
    int bracketCount = 0;
    int squareCount = 0;
    int epX = -1;
    int epY = -1;

    for (size_t characterIndex = startingIndex; characterIndex < inputLength; characterIndex++)
    {
        const char characterInFen = input[characterIndex];
        //printf("index: %d ", characterIndex);
        //printf("currentPhase: %d", currentPhase);
        //printf(" char: %c\n", characterInFen);
        //printf("     bracketcount %d", bracketCount);
        //printf(" squarecount: %d\n", squareCount);
        switch (currentPhase)
        {
        case 0:
            if (bracketCount == 7 && characterInFen == ' ')
            {
                //printf("     next phase brackcount = 7, char is empty\n");
                currentPhase++;
            }
            else
            {
                if (bracketCount > 7)
                {
                    bracketCount = 0;
                }

                if (squareCount > 7)
                {
                    squareCount = 0;
                }

                int square = (bracketCount * 8) + squareCount;

                switch (characterInFen)
                {

                case 'B':
                    //printf("    W bishop found %d\n", square);
                    *bitboardArray[WB] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'R':
                    //printf("    WR found\n");
                    *bitboardArray[WR] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'P':
                    //printf("     add white pawn %d\n", square);
                    *bitboardArray[WP] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'Q':
                    //printf("    WQ found\n");
                    *bitboardArray[WQ] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'K':
                    //printf("    WK\n");
                    *bitboardArray[WK] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'N':
                    //printf("    WN found\n");
                    *bitboardArray[WN] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'b':
                    //printf("    BB found\n");
                    *bitboardArray[BB] |= SQUARE_BBS[square];
                    squareCount++;
                    break;

                case 'p':
                    //printf("    BP sq: %d\n", square);
                    *bitboardArray[BP] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'q':
                    //printf("    BQ sq: %d\n", square);
                    *bitboardArray[BQ] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'r':
                    //printf("    BR sq: %d\n", square);
                    *bitboardArray[BR] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'n':
                    //printf("    BN sq: %d\n", square);
                    *bitboardArray[BN] |= SQUARE_BBS[square];
                    squareCount++;
                    break;
                case 'k':
                    //printf("    BK sq: %d\n", square);
                    *bitboardArray[BK] |= SQUARE_BBS[square];
                    squareCount++;
                    break;

                case '/':
                    //printf("    forward bracket slash\n", square);
                    squareCount = 0;
                    bracketCount++;
                    break;
                case '1':
                    //printf("    1 found\n");
                    squareCount += 1;
                    break;
                case '2':
                    //printf("    2 found\n");
                    squareCount += 2;
                    break;
                case '3':
                    //printf("    3 found\n");
                    squareCount += 3;
                    break;
                case '4':
                    //printf("    4 found\n");
                    squareCount += 4;
                    break;
                case '5':
                    //printf("    5 found\n");
                    squareCount += 5;
                    break;
                case '6':
                    //printf("    6 found\n");
                    squareCount += 6;
                    break;
                case '7':
                    //printf("    7 found\n");
                    squareCount += 7;
                    break;
                case '8':
                    //printf("    8 found\n");
                    squareCount += 8;
                    break;
                }
            }
            break;
        case 1:
            if (characterInFen == 'w')
            {
                *isWhite = true;
            }
            else if (characterInFen == 'b')
            {
                *isWhite = false;
            }
            else if (characterInFen == ' ')
            {
                currentPhase++;
            }
            break;
        case 2:
            switch (characterInFen)
            {
            case 'K':
                *castleRights[0] = true;
                break;
            case 'Q':
                *castleRights[1] = true;
                break;
            case 'k':
                *castleRights[2] = true;
                break;
            case 'q':
                *castleRights[3] = true;
                break;
            case '-':

                break;
            case ' ':
                currentPhase++;
                break;
            }
            break;
        case 3:
            if (characterInFen == ' ')
            {
                if (epX != -1)
                {
                    if (epY != -1)
                    {
                        *ep = (epY * 8) + epX;
                    }
                }
                currentPhase++;
            }
            else
            {
                switch (characterInFen)
                {
                case 'a':
                    epX = 0;
                    break;
                case 'b':
                    epX = 1;
                    break;
                case 'c':
                    epX = 2;
                    break;
                case 'd':
                    epX = 3;
                    break;
                case 'e':
                    epX = 4;
                    break;
                case 'f':
                    epX = 5;
                    break;
                case 'g':
                    epX = 6;
                    break;
                case 'h':
                    epX = 7;
                    break;
                case '1':
                    epY = 7;
                    break;
                case '2':
                    epY = 6;
                    break;
                case '3':
                    epY = 5;
                    break;
                case '4':
                    epY = 4;
                    break;
                case '5':
                    epY = 3;
                    break;
                case '6':
                    epY = 2;
                    break;
                case '7':
                    epY = 1;
                    break;
                case '8':
                    epY = 0;
                    break;
                }
            }
            break;
        case 4:
            break;
        case 5:
            break;
        }
    }
}


bool OutOfBounds(const int move)
{
    if (move < 0)
    {
        return true;
    }
    if (move > 63)
    {
        return true;
    }
    return false;
}

void PrintMoveNoNL(const int move[])
{    //starting
    if (OutOfBounds(move[MOVE_STARTING]) == true)
    {
        printf("%d", move[MOVE_STARTING]);
    }
    else
    {
        printf("%c", SQ_CHAR_X[move[MOVE_STARTING]]);
        printf("%c", SQ_CHAR_Y[move[MOVE_STARTING]]);
    }
    //target
    if (OutOfBounds(move[MOVE_TARGET]) == true)
    {
        printf("%d", move[MOVE_TARGET]);
    }
    else
    {
        printf("%c", SQ_CHAR_X[move[MOVE_TARGET]]);
        printf("%c", SQ_CHAR_Y[move[MOVE_TARGET]]);
    }
    int tag = move[MOVE_TAG];
    if (tag == TAG_BCaptureKnightPromotion || tag == TAG_BKnightPromotion || tag == TAG_WKnightPromotion || tag == TAG_WCaptureKnightPromotion)
    {
        printf("n");
    }
    else if (tag == TAG_BCaptureRookPromotion || tag == TAG_BRookPromotion || tag == TAG_WRookPromotion || tag == TAG_WCaptureRookPromotion)
    {
        printf("r");
    }
    else if (tag == TAG_BCaptureBishopPromotion || tag == TAG_BBishopPromotion || tag == TAG_WBishopPromotion || tag == TAG_WCaptureBishopPromotion)
    {
        printf("b");
    }
    else if (tag == TAG_BCaptureQueenPromotion || tag == TAG_BQueenPromotion || tag == TAG_WQueenPromotion || tag == TAG_WCaptureQueenPromotion)
    {
        printf("q");
    }
}


unsigned long long PerftInlineGlobal(const int depth, const int ply)
{
    //if (depth == 0)
    //{
    //    return 1;
    //}

    int move_list[50][4];
    int move_count = 0;

    //Move generating variables
    const unsigned long long WHITE_OCCUPANCIES_LOCAL = bitboard_array_global[0] | bitboard_array_global[1] | bitboard_array_global[2] | bitboard_array_global[3] | bitboard_array_global[4] | bitboard_array_global[5];
    const unsigned long long BLACK_OCCUPANCIES_LOCAL = bitboard_array_global[6] | bitboard_array_global[7] | bitboard_array_global[8] | bitboard_array_global[9] | bitboard_array_global[10] | bitboard_array_global[11];
    const unsigned long long COMBINED_OCCUPANCIES_LOCAL = WHITE_OCCUPANCIES_LOCAL | BLACK_OCCUPANCIES_LOCAL;
    const unsigned long long EMPTY_OCCUPANCIES = ~COMBINED_OCCUPANCIES_LOCAL;
    unsigned long long temp_bitboard, check_bitboard = 0ULL, temp_pin_bitboard, temp_attack, temp_empty, temp_captures;
    int starting_square = NO_SQUARE, target_square = NO_SQUARE;

    int pinArray[8][2] =
    {
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
        { -1, -1 },
    };

    int pinNumber = 0;

#pragma region Generate Moves

    if (is_white_global == true)
    {
        int whiteKingCheckCount = 0;
        const int whiteKingPosition = BitscanForward(bitboard_array_global[WK]);

#pragma region pins and check

        //pawns
        temp_bitboard = bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[whiteKingPosition];
        if (temp_bitboard != 0)
        {
            const int pawn_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);

            check_bitboard = 1ULL << pawn_square;

            whiteKingCheckCount++;
        }

        //knights
        temp_bitboard = bitboard_array_global[BN] & KNIGHT_ATTACKS[whiteKingPosition];
        if (temp_bitboard != 0)
        {
            const int knight_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);

            check_bitboard = SQUARE_BBS[knight_square];

            whiteKingCheckCount++;
        }

        //bishops
        const unsigned long long bishopAttacksChecks = GetBishopAttacksFast(whiteKingPosition, BLACK_OCCUPANCIES_LOCAL);
        temp_bitboard = bitboard_array_global[BB] & bishopAttacksChecks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square] & WHITE_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square];
                whiteKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //queen
        temp_bitboard = bitboard_array_global[BQ] & bishopAttacksChecks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square] & WHITE_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square];
                
                whiteKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //rook
        const unsigned long long rook_attacks = GetRookAttacksFast(whiteKingPosition, BLACK_OCCUPANCIES_LOCAL);
        temp_bitboard = bitboard_array_global[BR] & rook_attacks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square] & WHITE_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square];
                
                whiteKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //queen
        temp_bitboard = bitboard_array_global[BQ] & rook_attacks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square] & WHITE_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][piece_square];
                
                whiteKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

#pragma endregion

        if (whiteKingCheckCount > 1)
        {
#pragma region White king
            const unsigned long long occupanciesWithoutWhiteKing = COMBINED_OCCUPANCIES_LOCAL & (~bitboard_array_global[WK]);
            temp_attack = KING_ATTACKS[whiteKingPosition];
            temp_empty = temp_attack & EMPTY_OCCUPANCIES;
            while (temp_empty != 0)
            {
                target_square = BitscanForward(temp_empty);
                temp_empty &= temp_empty - 1;

                if ((bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = whiteKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_NONE;
                move_list[move_count][MOVE_PIECE] = WK;
                move_count++;
            }

            //captures
            temp_captures = temp_attack & BLACK_OCCUPANCIES_LOCAL;
            while (temp_captures != 0)
            {
                target_square = BitscanForward(temp_captures);
                temp_captures &= temp_captures - 1;

                if ((bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                const unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                const unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = whiteKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                move_list[move_count][MOVE_PIECE] = WK;
                move_count++;
            }

#pragma endregion
        }
        else
        {

            if (whiteKingCheckCount == 0)
            {
                check_bitboard = MAX_ULONG;
            }

#pragma region White king
            const unsigned long long occupanciesWithoutWhiteKing = COMBINED_OCCUPANCIES_LOCAL & (~bitboard_array_global[WK]);
            temp_attack = KING_ATTACKS[whiteKingPosition];
            temp_empty = temp_attack & EMPTY_OCCUPANCIES;
            while (temp_empty != 0)
            {
                target_square = BitscanForward(temp_empty);
                temp_empty &= temp_empty - 1;

                if ((bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = whiteKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_NONE;
                move_list[move_count][MOVE_PIECE] = WK;
                move_count++;
            }

            //captures
            temp_captures = temp_attack & BLACK_OCCUPANCIES_LOCAL;
            while (temp_captures != 0)
            {
                target_square = BitscanForward(temp_captures);
                temp_captures &= temp_captures - 1;

                if ((bitboard_array_global[BP] & WHITE_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupanciesWithoutWhiteKing);
                if ((bitboard_array_global[BR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[BQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = whiteKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                move_list[move_count][MOVE_PIECE] = WK;
                move_count++;
            }

            if (whiteKingCheckCount == 0)
            {
                if (castle_rights_global[WKS_CASTLE_RIGHTS] == true)
                {
                    if (whiteKingPosition == E1) //king on e1
                    {
                        if ((WKS_EMPTY_BITBOARD & COMBINED_OCCUPANCIES_LOCAL) == 0) //f1 and g1 empty
                        {
                            if ((bitboard_array_global[WR] & SQUARE_BBS[H1]) != 0) //rook on h1
                            {
                                if (Is_Square_Attacked_By_Black_Global(F1, COMBINED_OCCUPANCIES_LOCAL) == false)
                                {
                                    if (Is_Square_Attacked_By_Black_Global(G1, COMBINED_OCCUPANCIES_LOCAL) == false)
                                    {
                                        move_list[move_count][MOVE_STARTING] = E1;
                                        move_list[move_count][MOVE_TARGET] = G1;
                                        move_list[move_count][MOVE_TAG] = TAG_WCASTLEKS;
                                        move_list[move_count][MOVE_PIECE] = WK;
                                        move_count++;
                                    }
                                }
                            }
                        }
                    }
                }
                if (castle_rights_global[WQS_CASTLE_RIGHTS] == true)
                {
                    if (whiteKingPosition == E1) //king on e1
                    {
                        if ((WQS_EMPTY_BITBOARD & COMBINED_OCCUPANCIES_LOCAL) == 0) //f1 and g1 empty
                        {
                            if ((bitboard_array_global[WR] & SQUARE_BBS[A1]) != 0) //rook on h1
                            {
                                if (Is_Square_Attacked_By_Black_Global(C1, COMBINED_OCCUPANCIES_LOCAL) == false)
                                {
                                    if (Is_Square_Attacked_By_Black_Global(D1, COMBINED_OCCUPANCIES_LOCAL) == false)
                                    {
                                        move_list[move_count][MOVE_STARTING] = E1;
                                        move_list[move_count][MOVE_TARGET] = C1;
                                        move_list[move_count][MOVE_TAG] = TAG_WCASTLEQS;
                                        move_list[move_count][MOVE_PIECE] = WK;
                                        move_count++;
                                    }
                                }
                            }
                        }
                    }
                }
            }

#pragma endregion

#pragma region White knight

            temp_bitboard = bitboard_array_global[WN];

            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1; //removes the knight from that square to not infinitely loop

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                temp_attack = ((KNIGHT_ATTACKS[starting_square] & BLACK_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard; //gets knight captures
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = WN;
                    move_count++;
                }

                temp_attack = ((KNIGHT_ATTACKS[starting_square] & EMPTY_OCCUPANCIES) & check_bitboard) & temp_pin_bitboard;

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = WN;
                    move_count++;
                }
            }
#pragma endregion

#pragma region White pawn

            temp_bitboard = bitboard_array_global[WP];

            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

#pragma region Pawn forward

                if ((SQUARE_BBS[starting_square - 8] & COMBINED_OCCUPANCIES_LOCAL) == 0) //if up one square is empty
                {
                    if (((SQUARE_BBS[starting_square - 8] & check_bitboard) & temp_pin_bitboard) != 0)
                    {
                        if ((SQUARE_BBS[starting_square] & RANK_7_BITBOARD) != 0) //if promotion
                        {
                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square - 8;
                            move_list[move_count][MOVE_TAG] = TAG_WQueenPromotion;
                            move_list[move_count][MOVE_PIECE] = WP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square - 8;
                            move_list[move_count][MOVE_TAG] = TAG_WRookPromotion;
                            move_list[move_count][MOVE_PIECE] = WP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square - 8;
                            move_list[move_count][MOVE_TAG] = TAG_WBishopPromotion;
                            move_list[move_count][MOVE_PIECE] = WP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square - 8;
                            move_list[move_count][MOVE_TAG] = TAG_WKnightPromotion;
                            move_list[move_count][MOVE_PIECE] = WP;
                            move_count++;

                        }
                        else
                        {
                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square - 8;
                            move_list[move_count][MOVE_TAG] = TAG_NONE;
                            move_list[move_count][MOVE_PIECE] = WP;
                            move_count++;
                        }
                    }

                    if ((SQUARE_BBS[starting_square] & RANK_2_BITBOARD) != 0) //if on rank 2
                    {
                        if (((SQUARE_BBS[starting_square - 16] & check_bitboard) & temp_pin_bitboard) != 0) //if not pinned or 
                        {
                            if (((SQUARE_BBS[starting_square - 16]) & COMBINED_OCCUPANCIES_LOCAL) == 0) //if up two squares and one square are empty
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = starting_square - 16;
                                move_list[move_count][MOVE_TAG] = TAG_DoublePawnWhite;
                                move_list[move_count][MOVE_PIECE] = WP;
                                move_count++;
                            }
                        }
                    }
                }

#pragma endregion

#pragma region Pawn captures

                temp_attack = ((WHITE_PAWN_ATTACKS[starting_square] & BLACK_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard; //if black piece diagonal to pawn

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    if ((SQUARE_BBS[starting_square] & RANK_7_BITBOARD) != 0) //if promotion
                    {
                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_WCaptureQueenPromotion;
                        move_list[move_count][MOVE_PIECE] = WP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_WCaptureRookPromotion;
                        move_list[move_count][MOVE_PIECE] = WP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_WCaptureBishopPromotion;
                        move_list[move_count][MOVE_PIECE] = WP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_WCaptureKnightPromotion;
                        move_list[move_count][MOVE_PIECE] = WP;
                        move_count++;
                    }
                    else
                    {
                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                        move_list[move_count][MOVE_PIECE] = WP;
                        move_count++;
                    }
                }

                if ((SQUARE_BBS[starting_square] & RANK_5_BITBOARD) != 0) //check rank for ep
                {
                    if (ep_global != NO_SQUARE)
                    {
                        if ((((WHITE_PAWN_ATTACKS[starting_square] & SQUARE_BBS[ep_global]) & check_bitboard) & temp_pin_bitboard) != 0)
                        {
                            if ((bitboard_array_global[WK] & RANK_5_BITBOARD) == 0) //if no king on rank 5
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = ep_global;
                                move_list[move_count][MOVE_TAG] = TAG_WHITEEP;
                                move_list[move_count][MOVE_PIECE] = WP;
                                move_count++;
                            }
                            else if ((bitboard_array_global[BR] & RANK_5_BITBOARD) == 0 && (bitboard_array_global[BQ] & RANK_5_BITBOARD) == 0) // if no b rook or queen on rank 5
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = ep_global;
                                move_list[move_count][MOVE_TAG] = TAG_WHITEEP;
                                move_list[move_count][MOVE_PIECE] = WP;
                                move_count++;
                            }
                            else //wk and br or bq on rank 5
                            {
                                unsigned long long occupancyWithoutEPPawns = COMBINED_OCCUPANCIES_LOCAL & ~SQUARE_BBS[starting_square];
                                occupancyWithoutEPPawns &= ~SQUARE_BBS[ep_global + 8];

                                const unsigned long long rookAttacksFromKing = GetRookAttacksFast(whiteKingPosition, occupancyWithoutEPPawns);

                                if ((rookAttacksFromKing & bitboard_array_global[BR]) == 0)
                                {
                                    if ((rookAttacksFromKing & bitboard_array_global[BQ]) == 0)
                                    {
                                        move_list[move_count][MOVE_STARTING] = starting_square;
                                        move_list[move_count][MOVE_TARGET] = ep_global;
                                        move_list[move_count][MOVE_TAG] = TAG_WHITEEP;
                                        move_list[move_count][MOVE_PIECE] = WP;
                                        move_count++;
                                    }
                                }
                            }
                        }
                    }
                }

#pragma endregion
            }

#pragma endregion

#pragma region White Rook
            temp_bitboard = bitboard_array_global[WR];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                const unsigned long long rookAttacks = GetRookAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((rookAttacks & BLACK_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = WR;
                    move_count++;
                }

                temp_attack = ((rookAttacks & EMPTY_OCCUPANCIES) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = WR;
                    move_count++;
                }
            }
#pragma endregion

#pragma region White bishop
            temp_bitboard = bitboard_array_global[WB];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                unsigned long long bishopAttacks = GetBishopAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((bishopAttacks & BLACK_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = WB;
                    move_count++;
                }

                temp_attack = ((bishopAttacks & EMPTY_OCCUPANCIES) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = WB;
                    move_count++;
                }
            }
#pragma endregion

#pragma region White Queen
            temp_bitboard = bitboard_array_global[WQ];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[whiteKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                unsigned long long queenAttacks = GetRookAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);
                queenAttacks |= GetBishopAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((queenAttacks & BLACK_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = WQ;
                    move_count++;
                }

                temp_attack = ((queenAttacks & EMPTY_OCCUPANCIES) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = WQ;
                    move_count++;
                }
            }
#pragma endregion
        }
    }
    else //black move
    {
        int blackKingCheckCount = 0;
        int blackKingPosition = (DEBRUIJN64[MAGIC * (bitboard_array_global[BK] ^ (bitboard_array_global[BK] - 1)) >> 58]);

#pragma region pins and check

        //pawns
        temp_bitboard = bitboard_array_global[WP] & BLACK_PAWN_ATTACKS[blackKingPosition];
        if (temp_bitboard != 0)
        {
            const int pawn_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);

            check_bitboard = SQUARE_BBS[pawn_square];

            blackKingCheckCount++;
        }

        //knights
        temp_bitboard = bitboard_array_global[WN] & KNIGHT_ATTACKS[blackKingPosition];
        if (temp_bitboard != 0)
        {
            const int knight_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);

            check_bitboard = SQUARE_BBS[knight_square];

            blackKingCheckCount++;
        }

        //bishops
        const unsigned long long bishopAttacksChecks = GetBishopAttacksFast(blackKingPosition, WHITE_OCCUPANCIES_LOCAL);
        temp_bitboard = bitboard_array_global[WB] & bishopAttacksChecks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square] & BLACK_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square];
                
                blackKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //queen
        temp_bitboard = bitboard_array_global[WQ] & bishopAttacksChecks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);

            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square] & BLACK_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square];
                
                blackKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //rook
        unsigned long long rook_attacks = GetRookAttacksFast(blackKingPosition, WHITE_OCCUPANCIES_LOCAL);
        temp_bitboard = bitboard_array_global[WR] & rook_attacks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square] & BLACK_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square];
                
                blackKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

        //queen
        temp_bitboard = bitboard_array_global[WQ] & rook_attacks;
        while (temp_bitboard != 0)
        {
            const int piece_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square] & BLACK_OCCUPANCIES_LOCAL;

            if (temp_pin_bitboard == 0)
            {
                check_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][piece_square];
                
                blackKingCheckCount++;
            }
            else
            {
                const int pinned_square = (DEBRUIJN64[MAGIC * (temp_pin_bitboard ^ (temp_pin_bitboard - 1)) >> 58]);
                temp_pin_bitboard &= temp_pin_bitboard - 1;

                if (temp_pin_bitboard == 0)
                {
                    pinArray[pinNumber][PINNED_SQUARE_INDEX] = pinned_square;
                    pinArray[pinNumber][PINNING_PIECE_INDEX] = piece_square;
                    pinNumber++;
                }
            }
            temp_bitboard &= temp_bitboard - 1;
        }

#pragma endregion

        if (blackKingCheckCount > 1)
        {
#pragma region Black king
            const unsigned long long occupancyWithoutBlackKing = COMBINED_OCCUPANCIES_LOCAL & (~bitboard_array_global[BK]);
            temp_attack = KING_ATTACKS[blackKingPosition] & WHITE_OCCUPANCIES_LOCAL;

            while (temp_attack != 0)
            {
                target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                temp_attack &= temp_attack - 1;

                if ((bitboard_array_global[WP] & BLACK_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = starting_square;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                move_list[move_count][MOVE_PIECE] = BK;
                move_count++;
            }

            temp_attack = KING_ATTACKS[blackKingPosition] & ~COMBINED_OCCUPANCIES_LOCAL;

            while (temp_attack != 0)
            {
                target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                temp_attack &= temp_attack - 1;

                if ((bitboard_array_global[WP] & WHITE_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = starting_square;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_NONE;
                move_list[move_count][MOVE_PIECE] = BK;
                move_count++;
            }
#pragma endregion
        }
        else
        {
            if (blackKingCheckCount == 0)
            {
                check_bitboard = MAX_ULONG;
            }

#pragma region Black pawns

            temp_bitboard = bitboard_array_global[BP];

            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

#pragma region Pawn forward

                if ((SQUARE_BBS[starting_square + 8] & COMBINED_OCCUPANCIES_LOCAL) == 0) //if up one square is empty
                {
                    if (((SQUARE_BBS[starting_square + 8] & check_bitboard) & temp_pin_bitboard) != 0)
                    {
                        if ((SQUARE_BBS[starting_square] & RANK_2_BITBOARD) != 0) //if promotion
                        {
                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square + 8;
                            move_list[move_count][MOVE_TAG] = TAG_BBishopPromotion;
                            move_list[move_count][MOVE_PIECE] = BP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square + 8;
                            move_list[move_count][MOVE_TAG] = TAG_BKnightPromotion;
                            move_list[move_count][MOVE_PIECE] = BP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square + 8;
                            move_list[move_count][MOVE_TAG] = TAG_BRookPromotion;
                            move_list[move_count][MOVE_PIECE] = BP;
                            move_count++;

                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square + 8;
                            move_list[move_count][MOVE_TAG] = TAG_BQueenPromotion;
                            move_list[move_count][MOVE_PIECE] = BP;
                            move_count++;
                        }
                        else
                        {
                            move_list[move_count][MOVE_STARTING] = starting_square;
                            move_list[move_count][MOVE_TARGET] = starting_square + 8;
                            move_list[move_count][MOVE_TAG] = TAG_NONE;
                            move_list[move_count][MOVE_PIECE] = BP;
                            move_count++;
                        }
                    }

                    if ((SQUARE_BBS[starting_square] & RANK_7_BITBOARD) != 0) //if on rank 2
                    {
                        if (((SQUARE_BBS[starting_square + 16] & check_bitboard) & temp_pin_bitboard) != 0)
                        {
                            if (((SQUARE_BBS[starting_square + 16]) & COMBINED_OCCUPANCIES_LOCAL) == 0) //if up two squares and one square are empty
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = starting_square + 16;
                                move_list[move_count][MOVE_TAG] = TAG_DoublePawnBlack;
                                move_list[move_count][MOVE_PIECE] = BP;
                                move_count++;
                            }
                        }
                    }
                }

#pragma endregion

#pragma region region Pawn captures

                temp_attack = ((BLACK_PAWN_ATTACKS[starting_square] & WHITE_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard; //if black piece diagonal to pawn

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]); //find the bit
                    temp_attack &= temp_attack - 1;

                    if ((SQUARE_BBS[starting_square] & RANK_2_BITBOARD) != 0) //if promotion
                    {
                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_BCaptureQueenPromotion;
                        move_list[move_count][MOVE_PIECE] = BP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_BCaptureRookPromotion;
                        move_list[move_count][MOVE_PIECE] = BP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_BCaptureKnightPromotion;
                        move_list[move_count][MOVE_PIECE] = BP;
                        move_count++;

                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_BCaptureBishopPromotion;
                        move_list[move_count][MOVE_PIECE] = BP;
                        move_count++;
                    }
                    else
                    {
                        move_list[move_count][MOVE_STARTING] = starting_square;
                        move_list[move_count][MOVE_TARGET] = target_square;
                        move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                        move_list[move_count][MOVE_PIECE] = BP;
                        move_count++;
                    }
                }

                if ((SQUARE_BBS[starting_square] & RANK_4_BITBOARD) != 0) //check rank for ep
                {
                    if (ep_global != NO_SQUARE)
                    {
                        if ((((BLACK_PAWN_ATTACKS[starting_square] & SQUARE_BBS[ep_global]) & check_bitboard) & temp_pin_bitboard) != 0)
                        {
                            if ((bitboard_array_global[BK] & RANK_4_BITBOARD) == 0) //if no king on rank 5
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = ep_global;
                                move_list[move_count][MOVE_TAG] = TAG_BLACKEP;
                                move_list[move_count][MOVE_PIECE] = BP;
                                move_count++;
                            }
                            else if ((bitboard_array_global[WR] & RANK_4_BITBOARD) == 0 && (bitboard_array_global[WQ] & RANK_4_BITBOARD) == 0) // if no b rook or queen on rank 5
                            {
                                move_list[move_count][MOVE_STARTING] = starting_square;
                                move_list[move_count][MOVE_TARGET] = ep_global;
                                move_list[move_count][MOVE_TAG] = TAG_BLACKEP;
                                move_list[move_count][MOVE_PIECE] = BP;
                                move_count++;
                            }
                            else //wk and br or bq on rank 5
                            {
                                unsigned long long occupancyWithoutEPPawns = COMBINED_OCCUPANCIES_LOCAL & ~SQUARE_BBS[starting_square];
                                occupancyWithoutEPPawns &= ~SQUARE_BBS[ep_global - 8];

                                unsigned long long rookAttacksFromKing = GetRookAttacksFast(blackKingPosition, occupancyWithoutEPPawns);

                                if ((rookAttacksFromKing & bitboard_array_global[WR]) == 0)
                                {
                                    if ((rookAttacksFromKing & bitboard_array_global[WQ]) == 0)
                                    {
                                        move_list[move_count][MOVE_STARTING] = starting_square;
                                        move_list[move_count][MOVE_TARGET] = ep_global;
                                        move_list[move_count][MOVE_TAG] = TAG_BLACKEP;
                                        move_list[move_count][MOVE_PIECE] = BP;
                                        move_count++;
                                    }
                                }
                            }
                        }
                    }
                }

#pragma endregion
            }
#pragma endregion

#pragma region black Knight
            temp_bitboard = bitboard_array_global[BN];

            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]); //looks for the startingSquare
                temp_bitboard &= temp_bitboard - 1; //removes the knight from that square to not infinitely loop

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                temp_attack = ((KNIGHT_ATTACKS[starting_square] & WHITE_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard; //gets knight captures
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = BN;
                    move_count++;
                }

                temp_attack = ((KNIGHT_ATTACKS[starting_square] & (~COMBINED_OCCUPANCIES_LOCAL)) & check_bitboard) & temp_pin_bitboard;

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = BN;
                    move_count++;
                }
            }
#pragma endregion

#pragma region Black bishop
            temp_bitboard = bitboard_array_global[BB];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                const unsigned long long bishopAttacks = GetBishopAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((bishopAttacks & WHITE_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = BB;
                    move_count++;
                }

                temp_attack = ((bishopAttacks & (~COMBINED_OCCUPANCIES_LOCAL)) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = BB;
                    move_count++;
                }
            }
#pragma endregion

#pragma region Black Rook
            temp_bitboard = bitboard_array_global[BR];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                unsigned long long rookAttacks = GetRookAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((rookAttacks & WHITE_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = BR;
                    move_count++;
                }

                temp_attack = ((rookAttacks & (~COMBINED_OCCUPANCIES_LOCAL)) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = BR;
                    move_count++;
                }
            }
#pragma endregion

#pragma region Black queen

            temp_bitboard = bitboard_array_global[BQ];
            while (temp_bitboard != 0)
            {
                starting_square = (DEBRUIJN64[MAGIC * (temp_bitboard ^ (temp_bitboard - 1)) >> 58]);
                temp_bitboard &= temp_bitboard - 1;

                temp_pin_bitboard = MAX_ULONG;
                if (pinNumber != 0)
                {
                    for (int i = 0; i < pinNumber; i++)
                    {
                        if (pinArray[i][PINNED_SQUARE_INDEX] == starting_square)
                        {
                            temp_pin_bitboard = INBETWEEN_BITBOARDS[blackKingPosition][pinArray[i][PINNING_PIECE_INDEX]];
                        }
                    }
                }

                unsigned long long queenAttacks = GetRookAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);
                queenAttacks |= GetBishopAttacksFast(starting_square, COMBINED_OCCUPANCIES_LOCAL);

                temp_attack = ((queenAttacks & WHITE_OCCUPANCIES_LOCAL) & check_bitboard) & temp_pin_bitboard;

                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                    move_list[move_count][MOVE_PIECE] = BQ;
                    move_count++;
                }

                temp_attack = ((queenAttacks & (~COMBINED_OCCUPANCIES_LOCAL)) & check_bitboard) & temp_pin_bitboard;
                while (temp_attack != 0)
                {
                    target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                    temp_attack &= temp_attack - 1;

                    move_list[move_count][MOVE_STARTING] = starting_square;
                    move_list[move_count][MOVE_TARGET] = target_square;
                    move_list[move_count][MOVE_TAG] = TAG_NONE;
                    move_list[move_count][MOVE_PIECE] = BQ;
                    move_count++;
                }
            }
#pragma endregion

#pragma region Black King

            temp_attack = KING_ATTACKS[blackKingPosition] & WHITE_OCCUPANCIES_LOCAL; //gets knight captures
            while (temp_attack != 0)
            {
                target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                temp_attack &= temp_attack - 1;

                if ((bitboard_array_global[WP] & BLACK_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                const unsigned long long occupancyWithoutBlackKing = COMBINED_OCCUPANCIES_LOCAL & (~bitboard_array_global[BK]);
                const unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                const unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = blackKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_CAPTURE;
                move_list[move_count][MOVE_PIECE] = BK;
                move_count++;
            }

            temp_attack = KING_ATTACKS[blackKingPosition] & (~COMBINED_OCCUPANCIES_LOCAL); //get knight moves to emtpy squares

            while (temp_attack != 0)
            {
                target_square = (DEBRUIJN64[MAGIC * (temp_attack ^ (temp_attack - 1)) >> 58]);
                temp_attack &= temp_attack - 1;

                if ((bitboard_array_global[WP] & BLACK_PAWN_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WN] & KNIGHT_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WK] & KING_ATTACKS[target_square]) != 0)
                {
                    continue;
                }
                const unsigned long long occupancyWithoutBlackKing = COMBINED_OCCUPANCIES_LOCAL & (~bitboard_array_global[BK]);
                const unsigned long long bishopAttacks = GetBishopAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WB] & bishopAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & bishopAttacks) != 0)
                {
                    continue;
                }
                const unsigned long long rookAttacks = GetRookAttacksFast(target_square, occupancyWithoutBlackKing);
                if ((bitboard_array_global[WR] & rookAttacks) != 0)
                {
                    continue;
                }
                if ((bitboard_array_global[WQ] & rookAttacks) != 0)
                {
                    continue;
                }

                move_list[move_count][MOVE_STARTING] = blackKingPosition;
                move_list[move_count][MOVE_TARGET] = target_square;
                move_list[move_count][MOVE_TAG] = TAG_NONE;
                move_list[move_count][MOVE_PIECE] = BK;
                move_count++;
            }
        }
        if (blackKingCheckCount == 0)
        {
            if (castle_rights_global[BKS_CASTLE_RIGHTS] == true)
            {
                if (blackKingPosition == E8) //king on e1
                {
                    if ((BKS_EMPTY_BITBOARD & COMBINED_OCCUPANCIES_LOCAL) == 0) //f1 and g1 empty
                    {
                        if ((bitboard_array_global[BR] & SQUARE_BBS[H8]) != 0) //rook on h1
                        {
                            if (Is_Square_Attacked_By_White_Global(F8, COMBINED_OCCUPANCIES_LOCAL) == false)
                            {
                                if (Is_Square_Attacked_By_White_Global(G8, COMBINED_OCCUPANCIES_LOCAL) == false)
                                {
                                    move_list[move_count][MOVE_STARTING] = E8;
                                    move_list[move_count][MOVE_TARGET] = G8;
                                    move_list[move_count][MOVE_TAG] = TAG_BCASTLEKS;
                                    move_list[move_count][MOVE_PIECE] = BK;
                                    move_count++;
                                }
                            }
                        }
                    }
                }
            }
            if (castle_rights_global[BQS_CASTLE_RIGHTS] == true)
            {
                if (blackKingPosition == E8) //king on e1
                {
                    if ((BQS_EMPTY_BITBOARD & COMBINED_OCCUPANCIES_LOCAL) == 0) //f1 and g1 empty
                    {
                        if ((bitboard_array_global[BR] & SQUARE_BBS[A8]) != 0) //rook on h1
                        {
                            if (Is_Square_Attacked_By_White_Global(C8, COMBINED_OCCUPANCIES_LOCAL) == false)
                            {
                                if (Is_Square_Attacked_By_White_Global(D8, COMBINED_OCCUPANCIES_LOCAL) == false)
                                {
                                    move_list[move_count][MOVE_STARTING] = E8;
                                    move_list[move_count][MOVE_TARGET] = C8;
                                    move_list[move_count][MOVE_TAG] = TAG_BCASTLEQS;
                                    move_list[move_count][MOVE_PIECE] = BK;
                                    move_count++;
                                }
                            }
                        }
                    }
                }
            }
#pragma endregion
        }
    }

#pragma endregion

    if (depth == 1)
    {
        return move_count;
    }

    unsigned long long nodes = 0;// , priorNodes;
    const int copyEp = ep_global;
    const bool copy_castle[4] =
    {
        castle_rights_global[0],
        castle_rights_global[1],
        castle_rights_global[2],
        castle_rights_global[3],
    };

    for (size_t move_index = 0; move_index < move_count; ++move_index)
    {
        const int startingSquare = move_list[move_index][MOVE_STARTING];
        const int targetSquare = move_list[move_index][MOVE_TARGET];
        const int piece = move_list[move_index][MOVE_PIECE];
        const int tag = move_list[move_index][MOVE_TAG];

        int captureIndex = -1;

#pragma region Makemove

        is_white_global = !is_white_global;
        switch (tag)
        {
        case TAG_NONE: //none
        case TAG_CHECK: //check
            bitboard_array_global[piece] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case TAG_CAPTURE: //capture
        case TAG_CHECK_CAPTURE: //check cap
            bitboard_array_global[piece] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            if (PieceIsWhite(piece) == true)
            {
                for (size_t i = BLACK_START_INDEX; i <= BLACK_END_INDEX; ++i)
                {
                    if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                    {
                        captureIndex = i;
                        break;
                    }
                }
                bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            }
            else //is black
            {
                for (size_t i = WHITE_START_INDEX; i <= WHITE_END_INDEX; ++i)
                {
                    if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                    {
                        captureIndex = i;
                        break;
                    }
                }
                bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];
            }

            ep_global = NO_SQUARE;
            break;
        case TAG_WHITEEP: //white ep
            //move piece
            bitboard_array_global[WP] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[WP] &= ~SQUARE_BBS[startingSquare];
            //remove 
            bitboard_array_global[BP] &= ~SQUARE_BBS[targetSquare + 8];
            ep_global = NO_SQUARE;
            break;
        case TAG_BLACKEP: //black ep
            //move piece
            bitboard_array_global[BP] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[BP] &= ~SQUARE_BBS[startingSquare];
            //remove white pawn square up
            bitboard_array_global[WP] &= ~SQUARE_BBS[targetSquare - 8];
            ep_global = NO_SQUARE;
            break;

#pragma region Castling

        case TAG_WCASTLEKS: //WKS
            //white king
            bitboard_array_global[WK] |= SQUARE_BBS[G1];
            bitboard_array_global[WK] &= ~SQUARE_BBS[E1];
            //white rook
            bitboard_array_global[WR] |= SQUARE_BBS[F1];
            bitboard_array_global[WR] &= ~SQUARE_BBS[H1];
            castle_rights_global[WKS_CASTLE_RIGHTS] = false;
            castle_rights_global[WQS_CASTLE_RIGHTS] = false;
            ep_global = NO_SQUARE;
            break;
        case TAG_WCASTLEQS: //WQS
            //white king
            bitboard_array_global[WK] |= SQUARE_BBS[C1];
            bitboard_array_global[WK] &= ~SQUARE_BBS[E1];
            //white rook
            bitboard_array_global[WR] |= SQUARE_BBS[D1];
            bitboard_array_global[WR] &= ~SQUARE_BBS[A1];
            castle_rights_global[WKS_CASTLE_RIGHTS] = false;
            castle_rights_global[WQS_CASTLE_RIGHTS] = false;
            ep_global = NO_SQUARE;
            break;
        case TAG_BCASTLEKS: //BKS
            //white king
            bitboard_array_global[BK] |= SQUARE_BBS[G8];
            bitboard_array_global[BK] &= ~SQUARE_BBS[E8];
            //white rook
            bitboard_array_global[BR] |= SQUARE_BBS[F8];
            bitboard_array_global[BR] &= ~SQUARE_BBS[H8];

            castle_rights_global[BKS_CASTLE_RIGHTS] = false;
            castle_rights_global[BQS_CASTLE_RIGHTS] = false;
            ep_global = NO_SQUARE;
            break;
        case TAG_BCASTLEQS: //BQS
            //white king
            bitboard_array_global[BK] |= SQUARE_BBS[C8];
            bitboard_array_global[BK] &= ~SQUARE_BBS[E8];
            //white rook
            bitboard_array_global[BR] |= SQUARE_BBS[D8];
            bitboard_array_global[BR] &= ~SQUARE_BBS[A8];
            castle_rights_global[BKS_CASTLE_RIGHTS] = false;
            castle_rights_global[BQS_CASTLE_RIGHTS] = false;
            ep_global = NO_SQUARE;
            break;

#pragma endregion

#pragma region Promotion makemove

        case TAG_BKnightPromotion: //BNPr
            bitboard_array_global[BN] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case TAG_BBishopPromotion: //BBPr
            bitboard_array_global[BB] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case TAG_BQueenPromotion: //BQPr
            bitboard_array_global[BQ] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case TAG_BRookPromotion: //BRPr
            bitboard_array_global[BR] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case 12: //WNPr
            bitboard_array_global[WN] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case 13: //WBPr
            bitboard_array_global[WB] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case 14: //WQPr
            bitboard_array_global[WQ] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case 15: //WRPr
            bitboard_array_global[WR] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            break;
        case 16: //BNPrCAP
            bitboard_array_global[BN] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = WHITE_START_INDEX; i <= WHITE_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 17: //BBPrCAP
            bitboard_array_global[BB] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = WHITE_START_INDEX; i <= WHITE_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 18: //BQPrCAP
            bitboard_array_global[BQ] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = WHITE_START_INDEX; i <= WHITE_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 19: //BRPrCAP
            bitboard_array_global[BR] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = WHITE_START_INDEX; i <= WHITE_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 20: //WNPrCAP
            bitboard_array_global[WN] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = BLACK_START_INDEX; i <= BLACK_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 21: //WBPrCAP
            bitboard_array_global[WB] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = BLACK_START_INDEX; i <= BLACK_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 22: //WQPrCAP
            bitboard_array_global[WQ] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];
            ep_global = NO_SQUARE;
            for (size_t i = BLACK_START_INDEX; i <= BLACK_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];

            break;
        case 23: //WRPrCAP
            bitboard_array_global[WR] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[startingSquare];

            ep_global = NO_SQUARE;
            for (size_t i = BLACK_START_INDEX; i <= BLACK_END_INDEX; ++i)
            {
                if ((bitboard_array_global[i] & SQUARE_BBS[targetSquare]) != 0)
                {
                    captureIndex = i;
                    break;
                }
            }
            bitboard_array_global[captureIndex] &= ~SQUARE_BBS[targetSquare];
            break;

#pragma endregion

        case 24: //WDouble
            bitboard_array_global[WP] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[WP] &= ~SQUARE_BBS[startingSquare];
            ep_global = targetSquare + 8;
            break;
        case 25: //BDouble
            bitboard_array_global[BP] |= SQUARE_BBS[targetSquare];
            bitboard_array_global[BP] &= ~SQUARE_BBS[startingSquare];
            ep_global = targetSquare - 8;
            break;
        }

        if (piece == WK)
        {
            castle_rights_global[WKS_CASTLE_RIGHTS] = false;
            castle_rights_global[WQS_CASTLE_RIGHTS] = false;
        }
        else if (piece == BK)
        {
            castle_rights_global[BKS_CASTLE_RIGHTS] = false;
            castle_rights_global[BQS_CASTLE_RIGHTS] = false;
        }
        else if (piece == WR)
        {
            if (castle_rights_global[WKS_CASTLE_RIGHTS] == true)
            {
                if ((bitboard_array_global[WR] & SQUARE_BBS[H1]) == 0)
                {
                    castle_rights_global[WKS_CASTLE_RIGHTS] = false;
                }
            }
            if (castle_rights_global[WQS_CASTLE_RIGHTS] == true)
            {
                if ((bitboard_array_global[WR] & SQUARE_BBS[A1]) == 0)
                {
                    castle_rights_global[WQS_CASTLE_RIGHTS] = false;
                }
            }
        }
        else if (piece == BR)
        {
            if (castle_rights_global[BKS_CASTLE_RIGHTS] == true)
            {
                if ((bitboard_array_global[BR] & SQUARE_BBS[H8]) == 0)
                {
                    castle_rights_global[BKS_CASTLE_RIGHTS] = false;
                }
            }
            if (castle_rights_global[BQS_CASTLE_RIGHTS] == true)
            {
                if ((bitboard_array_global[BR] & SQUARE_BBS[A8]) == 0)
                {
                    castle_rights_global[BQS_CASTLE_RIGHTS] = false;
                }
            }
        }

#pragma endregion

        const int priorNodes = nodes;
        nodes += PerftInlineGlobal(depth - 1, ply + 1);

#pragma region Unmakemove

        is_white_global = !is_white_global;
        switch (tag)
        {
        case TAG_NONE: //none
        case TAG_CHECK: //check
            bitboard_array_global[piece] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[targetSquare];

            break;
        case TAG_CAPTURE: //capture
        case TAG_CHECK_CAPTURE: //check cap
            bitboard_array_global[piece] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[piece] &= ~SQUARE_BBS[targetSquare];
            if (PieceIsWhite(piece) == true)
            {
                bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            }
            else //is black
            {
                bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            }

            break;
        case TAG_WHITEEP: //white ep
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WP] &= ~SQUARE_BBS[targetSquare];
            bitboard_array_global[BP] |= SQUARE_BBS[targetSquare + 8];

            break;
        case TAG_BLACKEP: //black ep
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BP] &= ~SQUARE_BBS[targetSquare];
            bitboard_array_global[WP] |= SQUARE_BBS[targetSquare - 8];

            break;
        case TAG_WCASTLEKS: //WKS
            //white king
            bitboard_array_global[WK] |= SQUARE_BBS[E1];
            bitboard_array_global[WK] &= ~SQUARE_BBS[G1];
            //white rook
            bitboard_array_global[WR] |= SQUARE_BBS[H1];
            bitboard_array_global[WR] &= ~SQUARE_BBS[F1];
            break;
        case TAG_WCASTLEQS: //WQS
            //white king
            bitboard_array_global[WK] |= SQUARE_BBS[E1];
            bitboard_array_global[WK] &= ~SQUARE_BBS[C1];
            //white rook
            bitboard_array_global[WR] |= SQUARE_BBS[A1];
            bitboard_array_global[WR] &= ~SQUARE_BBS[D1];
            break;
        case TAG_BCASTLEKS: //BKS
            //white king
            bitboard_array_global[BK] |= SQUARE_BBS[E8];
            bitboard_array_global[BK] &= ~SQUARE_BBS[G8];
            //white rook
            bitboard_array_global[BR] |= SQUARE_BBS[H8];
            bitboard_array_global[BR] &= ~SQUARE_BBS[F8];
            break;
        case TAG_BCASTLEQS: //BQS
            //white king
            bitboard_array_global[BK] |= SQUARE_BBS[E8];
            bitboard_array_global[BK] &= ~SQUARE_BBS[C8];
            //white rook
            bitboard_array_global[BR] |= SQUARE_BBS[A8];
            bitboard_array_global[BR] &= ~SQUARE_BBS[D8];

            break;

#pragma region Promotion Unmakemove
        case TAG_BKnightPromotion: //BNPr
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BN] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_BBishopPromotion: //BBPr
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BB] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_BQueenPromotion: //BQPr
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BQ] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_BRookPromotion: //BRPr
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BR] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_WKnightPromotion: //WNPr
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WN] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_WBishopPromotion: //WBPr
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WB] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_WQueenPromotion: //WQPr
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WQ] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_WRookPromotion: //WRPr
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WR] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_BCaptureKnightPromotion: //BNPrCAP
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BN] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_BCaptureBishopPromotion: //BBPrCAP
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BB] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];

            break;
        case TAG_BCaptureQueenPromotion: //BQPrCAP
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BQ] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_BCaptureRookPromotion: //BRPrCAP
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BR] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_WCaptureKnightPromotion: //WNPrCAP
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WN] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_WCaptureBishopPromotion: //WBPrCAP
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WB] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_WCaptureQueenPromotion: //WQPrCAP
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WQ] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;
        case TAG_WCaptureRookPromotion: //WRPrCAP
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WR] &= ~SQUARE_BBS[targetSquare];

            bitboard_array_global[captureIndex] |= SQUARE_BBS[targetSquare];
            break;

#pragma endregion

        case TAG_DoublePawnWhite: //WDouble
            bitboard_array_global[WP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[WP] &= ~SQUARE_BBS[targetSquare];
            break;
        case TAG_DoublePawnBlack: //BDouble
            bitboard_array_global[BP] |= SQUARE_BBS[startingSquare];
            bitboard_array_global[BP] &= ~SQUARE_BBS[targetSquare];
            break;
        }

        castle_rights_global[0] = copy_castle[0];
        castle_rights_global[1] = copy_castle[1];
        castle_rights_global[2] = copy_castle[2];
        castle_rights_global[3] = copy_castle[3];
        ep_global = copyEp;

        //if (epGlobal != NO_SQUARE)
        //{
        //    std::cout << "   ep: " << SQ_CHAR_X[epGlobal] << SQ_CHAR_Y[epGlobal] << '\n';
        //}

#pragma endregion

//if (ply == 0)
//{
    //PrintMoveNoNL(move_list[move_index]);
    //printf(": %llu\n", nodes - priorNodes);
//}
    }

    return nodes;
}


void RunPerftInlineGlobal(const int depth)
{
    CopyGlobalBoardGlobal();

    clock_t start_time = clock(); // Get the initial time

    unsigned long long nodes = PerftInlineGlobal(depth, 0);

    clock_t end_time = clock();
    double elapsed_milliseconds = (double)(end_time - start_time) * 1000.0 / CLOCKS_PER_SEC;
    printf("Nodes: %llu\n", nodes);
    printf("Elapsed time: %.2f milliseconds\n", elapsed_milliseconds);
}

void print_all()
{
    for (size_t i = 0; i < 12; i++)
    {
        std::cout << i << ": " << *bitboardArray[i] << '\n';
    }
}


int main()
{
    CreateBoard();

    ParseFenGlobal(FEN_STARTING_POSITION, 0); //reads in starting position
    //std::cin.get();
    print_all();
    RunPerftInlineGlobal(1);

    return 0;
}