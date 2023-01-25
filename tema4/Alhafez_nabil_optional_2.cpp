//#include <iostream>
//#include <cstdio>
//#include <fstream>
//
//using namespace std;
//
//
//#define INVALID 0
//#define WIN 1
//#define DRAW 2
//#define LOSE 3
//
//#define MAX_CONF 1000000
//
//char sol[9];
//char cod[9];
//int ans[MAX_CONF];
//char write[4][10] = { "invalid", "win", "draw", "lose" };
//
//bool check( char c ) {
//    for ( int i = 0; i < 3; ++i ) {
//        int count1 = 0, count2 = 0;
//        for ( int j = 0; j < 3; ++j ) {
//            if ( sol[i * 3 + j] == c )
//                ++count1;
//            if ( sol[i + 3 * j] == c )
//                ++count2;
//        }
//
//        if ( count1 == 3 || count2 == 3 )
//            return true;
//    }
//
//    int count = 0;
//    for ( int i = 0; i < 9; i += 4 )
//        if ( sol[i] == c )
//            ++count;
//    if ( count == 3 )
//        return true;
//
//    count = 0;
//    for ( int i = 2; i < 7; i += 2 )
//        if ( sol[i] == c )
//            ++count;
//    if ( count == 3 )
//        return true;
//
//    return false;
//}
//
//int get_key( char a[] ) {
//    int key = 0;
//    for ( int i = 0; i < 9; ++i ) {
//        if ( a[i] == '.' )
//            key = key * 3 + 1;
//        else if ( a[i] == 'X' )
//            key = key * 3 + 2;
//        else
//            key = key * 3 + 3;
//    }
//
//    return key;
//}
//
//int dfs( char c ) {
//    bool stop = true;
//    bool result[4] = { false, false, false, false };
//
//    for ( int i = 0; i < 9; ++i )
//        if ( sol[i] == '.' ) {
//            stop = false;
//
//            sol[i] = c;
//
//            if ( check( c ) ) {
//                if ( c == 'X' )
//                    result[WIN] = true;
//                else
//                    result[LOSE] = true;
//            } else {
//                if ( c == 'X' )
//                    result[dfs( '0' )] = true;
//                else
//                    result[dfs( 'X' )] = true;
//            }
//
//            sol[i] = '.';
//        }
//
//    int key = get_key( sol );
//
//    if ( stop )
//        return ans[key] = DRAW;
//    else {
//        if ( c == 'X' ) {
//            for ( int i = 3; i > 0; --i )
//                if ( result[i] )
//                    ans[key] = i;
//        }
//        else {
//            for ( int i = 1; i < 4; ++i )
//                if ( result[i] )
//                    ans[key] = i;
//        }
//
//        return ans[key];
//    }
//}
//
//int main() {
//    ifstream fin( "xsizero.in" );
//    freopen( "xsizero.out", "w", stdout );
//
//    for ( int i = 0; i < 9; ++i )
//        sol[i] = '.';
//
//    dfs( 'X' );
//
//    int t = 1;
//    string s[3];
//    while ( fin >> s[0] ) {
//        fin >> s[1] >> s[2];
//
//        for ( int i = 0; i < 3; ++i )
//            for ( int j = 0; j < 3; ++j )
//                cod[i * 3 + j] = s[i][j];
//
//        printf( "Testul #%d: ", t );
//        puts( write[ans[get_key( cod )]] );
//
//        ++t;
//    }
//}