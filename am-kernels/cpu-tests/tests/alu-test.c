#include "trap.h"
int main(void) {
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x+y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x+y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x+y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x+y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x+y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x+y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x+y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x+y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x+y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x+y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x+y)!=(signed int)-3) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x+y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)2147483644) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)2147483645) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x+y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x+y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)2147483645) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x+y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x+y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)3) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x+y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x+y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)-3) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x+y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x-y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x-y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x-y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x-y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x-y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x-y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)3) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x-y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)-3) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)-3) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)-2147483644) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x-y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x^y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x^y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x^y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x^y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x^y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x^y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x^y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x^y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x^y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x^y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)-3) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)3) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)2147483644) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)2147483645) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x^y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x&y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x&y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x&y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x&y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x&y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x&y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x&y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x&y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x&y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x&y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x&y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x&y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x&y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x|y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x|y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x|y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x|y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x|y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)-2147483645) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x|y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x|y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)3) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x|y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x|y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x|y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x<<y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x<<y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x<<y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)-8) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x<<y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x<<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x<<y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x<<y)!=(signed int)8) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x>>y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)-1073741824) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)-536870912) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x>>y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)-1073741824) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)-536870912) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x>>y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x>>y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x>>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x&&y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x||y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x||y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x>y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x<y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x>=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x<=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x==y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x!=y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x*y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-1;
  if ((signed int)(x*y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=0;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x*y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x*y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x*y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=0;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x*y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x*y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=0;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x*y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=0;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=0;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x*y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x*y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)-4) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x*y)!=(signed int)4) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)-2147483646) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x*y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x/y)!=(signed int)1073741824) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)-2147483648) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)-1073741824) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x/y)!=(signed int)1073741823) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x/y)!=(signed int)2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)-2147483647) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)-1073741823) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x/y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x/y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483648;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2147483647;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=-2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2147483648; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2147483647;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-2;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=-1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-2147483647; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=-1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-2; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)-2) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=-1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=-1; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)-1) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=0; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=1;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=1; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)1) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)2) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483646;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed int x=2147483646; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)2147483646) {
  halt(1);}}
{
  volatile signed int x=2147483647; volatile signed int y=2147483647;
  if ((signed int)(x%y)!=(signed int)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x+y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x+y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x+y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x+y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x+y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x+y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x+y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x+y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x+y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x+y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x+y)!=(signed short)-3) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x+y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)32764) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)32765) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x+y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x+y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)32765) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x+y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x+y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)3) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x+y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x+y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)-3) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x+y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x-y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x-y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x-y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x-y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x-y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x-y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)3) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x-y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)-3) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)-3) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)-32764) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x-y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x^y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x^y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x^y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x^y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x^y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x^y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x^y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x^y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x^y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x^y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)-3) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)3) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)32764) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)32765) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x^y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x&y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x&y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x&y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x&y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x&y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x&y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x&y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x&y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x&y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x&y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x&y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x&y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x&y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x|y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x|y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x|y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x|y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x|y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)-32765) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x|y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x|y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)3) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x|y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x|y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x|y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x<<y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x<<y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x<<y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)-8) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x<<y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x<<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x<<y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x<<y)!=(signed short)8) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x>>y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)-16384) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)-8192) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x>>y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)-16384) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)-8192) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x>>y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x>>y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x>>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x&&y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x||y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x||y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x>y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x<y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x>=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x<=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x==y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x!=y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x*y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x*y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=0;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x*y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x*y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x*y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=0;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x*y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x*y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=0;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x*y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=0;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=0;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x*y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x*y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)-4) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x*y)!=(signed short)4) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)-32766) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x*y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x/y)!=(signed short)16384) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x/y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)-32768) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)-16384) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x/y)!=(signed short)16383) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x/y)!=(signed short)32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)-32767) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)-16383) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x/y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x/y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32768;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-32767;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=-1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-32768; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-32767;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-2;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=-1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-32767; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=-1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-2; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)-2) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=-1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=-1; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)-1) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=0; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=1;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=1; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)1) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=2;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=2; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)2) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32766;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed short x=32766; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)32766) {
  halt(1);}}
{
  volatile signed short x=32767; volatile signed short y=32767;
  if ((signed short)(x%y)!=(signed short)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x+y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x+y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x+y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x+y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x+y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x+y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x+y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x+y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x+y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x+y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x+y)!=(signed char)-3) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x+y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)124) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)125) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x+y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x+y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)125) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x+y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x+y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)3) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x+y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x+y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)-3) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x+y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x-y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x-y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x-y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x-y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x-y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x-y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)3) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x-y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)-3) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)-3) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)-124) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x-y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x^y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x^y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x^y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x^y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x^y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x^y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x^y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x^y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x^y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x^y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)-3) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)3) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)124) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)125) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x^y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x&y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x&y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x&y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x&y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x&y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x&y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x&y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x&y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x&y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x&y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x&y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x&y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x&y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x|y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x|y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x|y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x|y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x|y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)-125) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x|y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x|y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)3) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x|y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x|y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x|y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x<<y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x<<y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x<<y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)-8) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x<<y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x<<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x<<y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x<<y)!=(signed char)8) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x>>y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)-64) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)-32) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x>>y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)-64) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)-32) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x>>y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x>>y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x>>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x&&y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x||y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x||y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x>y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x<y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x>=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x<=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x==y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x!=y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x*y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x*y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=0;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x*y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x*y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x*y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=0;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x*y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x*y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=0;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x*y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=0;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=0;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x*y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x*y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)-4) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x*y)!=(signed char)4) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)-126) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x*y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x/y)!=(signed char)64) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x/y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)-128) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)-64) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x/y)!=(signed char)63) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x/y)!=(signed char)127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)-127) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)-63) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x/y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x/y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-128;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-127;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=-1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-128; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-127;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-2;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=-1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-127; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=-1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-2; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)-2) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=-1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=-1; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)-1) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=0; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=1;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=1; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)1) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=2;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=2; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)2) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=126;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile signed char x=126; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)126) {
  halt(1);}}
{
  volatile signed char x=127; volatile signed char y=127;
  if ((signed char)(x%y)!=(signed char)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x+y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x+y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x+y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x+y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x+y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x+y)!=(unsigned int)-3) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x+y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)2147483644) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x+y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x+y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x+y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x+y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x+y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x+y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)-3) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x+y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x-y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)-3) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)-3) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483644) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x-y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x^y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x^y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x^y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x^y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x^y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x^y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x^y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)-3) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)2147483644) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)2147483645) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x^y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x&y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x&y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x&y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x&y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x&y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)-2147483645) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x|y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x|y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x|y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x|y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x|y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x<<y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x<<y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x<<y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)-8) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x<<y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x<<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x<<y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x<<y)!=(unsigned int)8) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x>>y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)1073741824) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)536870912) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x>>y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)1073741824) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)536870912) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x>>y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)1073741823) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x>>y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)1073741823) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x>>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x&&y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x||y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x||y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x>=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x<=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x==y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x!=y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-1;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=0;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x*y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x*y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=0;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x*y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x*y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=0;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x*y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=0;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=0;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x*y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x*y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)-4) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x*y)!=(unsigned int)4) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)-2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x*y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)1073741824) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)1073741824) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)-1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x/y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483648;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=-2;
  if ((unsigned int)(x%y)!=(unsigned int)-2147483648) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2147483648; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-2;
  if ((unsigned int)(x%y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=-1;
  if ((unsigned int)(x%y)!=(unsigned int)-2147483647) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=-2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-2;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=-1;
  if ((unsigned int)(x%y)!=(unsigned int)-2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=-2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=-1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)3) {
  halt(1);}}
{
  volatile unsigned int x=-1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=0; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=1;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=1; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)1) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)2) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483646;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned int x=2147483646; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)2147483646) {
  halt(1);}}
{
  volatile unsigned int x=2147483647; volatile unsigned int y=2147483647;
  if ((unsigned int)(x%y)!=(unsigned int)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x+y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x+y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x+y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x+y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x+y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x+y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x+y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x+y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x+y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x+y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x+y)!=(unsigned short)65533) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x+y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)32764) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)32765) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x+y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x+y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)32765) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x+y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x+y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x+y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x+y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)65533) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x+y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x-y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x-y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x-y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x-y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x-y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x-y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x-y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)65533) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)65533) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)32772) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x-y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x^y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x^y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x^y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x^y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x^y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x^y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x^y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x^y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x^y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x^y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)65533) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)32764) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)32765) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x^y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x&y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x&y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x&y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x&y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x&y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x&y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x&y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x&y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x&y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x&y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x&y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x&y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x&y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x|y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x|y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x|y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x|y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x|y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)32771) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x|y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x|y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x|y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x|y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x|y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x<<y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x<<y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x<<y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)65528) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x<<y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x<<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x<<y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x<<y)!=(unsigned short)8) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x>>y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)16384) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)8192) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x>>y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)16384) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)8192) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x>>y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)16383) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x>>y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)16383) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x>>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x&&y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x||y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x||y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x>y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x<y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x>=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x<=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x==y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x!=y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x*y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x*y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=0;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x*y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x*y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x*y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=0;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x*y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x*y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=0;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x*y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=0;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=0;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x*y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x*y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)65532) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x*y)!=(unsigned short)4) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)32770) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x*y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)16384) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)16384) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)65535) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)32767) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x/y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32768;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32769;
  if ((unsigned short)(x%y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65534;
  if ((unsigned short)(x%y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=65535;
  if ((unsigned short)(x%y)!=(unsigned short)32768) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32768; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32769;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65534;
  if ((unsigned short)(x%y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=65535;
  if ((unsigned short)(x%y)!=(unsigned short)32769) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=32769; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65534;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=65535;
  if ((unsigned short)(x%y)!=(unsigned short)65534) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=65534; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=65535;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)3) {
  halt(1);}}
{
  volatile unsigned short x=65535; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=0; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=1;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=1; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)1) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=2;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=2; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)2) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32766;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned short x=32766; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)32766) {
  halt(1);}}
{
  volatile unsigned short x=32767; volatile unsigned short y=32767;
  if ((unsigned short)(x%y)!=(unsigned short)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x+y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x+y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x+y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x+y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x+y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x+y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x+y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x+y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x+y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x+y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x+y)!=(unsigned char)253) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x+y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)124) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)125) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x+y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x+y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)125) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x+y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x+y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x+y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x+y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)253) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x+y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x-y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x-y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x-y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x-y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x-y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x-y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x-y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)253) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)253) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)132) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x-y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x^y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x^y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x^y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x^y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x^y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x^y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x^y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x^y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x^y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x^y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)253) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)124) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)125) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x^y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x&y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x&y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x&y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x&y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x&y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x&y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x&y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x&y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x&y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x&y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x&y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x&y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x&y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x|y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x|y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x|y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x|y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x|y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)131) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x|y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x|y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x|y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x|y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x|y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x<<y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x<<y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x<<y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)248) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x<<y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x<<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x<<y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x<<y)!=(unsigned char)8) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x>>y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)64) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)32) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x>>y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)64) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)32) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x>>y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)63) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x>>y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)63) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x>>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x&&y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x||y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x||y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x>y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x<y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x>=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x<=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x==y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x!=y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x*y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x*y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=0;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x*y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x*y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x*y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=0;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x*y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x*y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=0;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x*y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=0;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=0;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x*y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x*y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)252) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x*y)!=(unsigned char)4) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)130) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x*y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)64) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)64) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)255) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)127) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x/y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=128;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=129;
  if ((unsigned char)(x%y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=254;
  if ((unsigned char)(x%y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=255;
  if ((unsigned char)(x%y)!=(unsigned char)128) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=128; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=129;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=254;
  if ((unsigned char)(x%y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=255;
  if ((unsigned char)(x%y)!=(unsigned char)129) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=129; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=254;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=255;
  if ((unsigned char)(x%y)!=(unsigned char)254) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=254; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=255;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)3) {
  halt(1);}}
{
  volatile unsigned char x=255; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=0; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=1;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=1; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)1) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=2;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=2; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)2) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=126;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
{
  volatile unsigned char x=126; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)126) {
  halt(1);}}
{
  volatile unsigned char x=127; volatile unsigned char y=127;
  if ((unsigned char)(x%y)!=(unsigned char)0) {
  halt(1);}}
  return 0;
}
