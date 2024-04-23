// 백준8911.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <cctype>
#include <string>
#include <cmath>

using namespace std;
class Turtle {
public:
   int x;
   int y;
   int maxX;
   int maxY;
   int minX;
   int minY;
   char dir;
   Turtle() :x(0), y(0), dir('U'), maxX(0), maxY(0), minX(0), minY(0) {}
   void f() {
      if (dir == 'U') {
         y++;
         if (y > maxY) maxY = y;
      }
      else if (dir == 'D') {
         y--;
         if (y < minY) minY = y;
      }
      else if (dir == 'L') {
         x--;
         if (x < minX) minX = x;
      }
      else if (dir == 'R') {
         x++;
         if (x > maxX) maxX = x;
      }
   }
   void b() {
      if (dir == 'U') {
         y--;
         if (y < minY) minY = y;
      }
      else if (dir == 'D') {
         y++;
         if (y > maxY) maxY = y;
      }
      else if (dir == 'L') {
         x++;
         if (x > maxX) maxX = x;
      }
      else if (dir == 'R') {
         x--;
         if (x < minX) minX = x;
      }
   }
   void l() {
      if (dir == 'U') {
         dir = 'L';
      }
      else if (dir == 'D') {
         dir = 'R';
      }
      else if (dir == 'L') {
         dir = 'D';
      }
      else if (dir == 'R') {
         dir = 'U';
      }
   }
   void r() {
      if (dir == 'U') {
         dir = 'R';
      }
      else if (dir == 'D') {
         dir = 'L';
      }
      else if (dir == 'L') {
         dir = 'U';
      }
      else if (dir == 'R') {
         dir = 'D';
      }
   }
};
int main()
{
   int n;
   cin >> n;
   string input = "FBLR";
   string* result = new string[n];
   bool invalid = false;
   for (int i = 0; i < n; i++) {
      cin >> result[i];
      if (result[i].size() > 500) {
         return 0;
      }
      for (int j = 0; j < result[i].size(); j++) {
         char c = toupper(result[i][j]);
         if (input.find(c) == string::npos) {
            invalid = true;
         }
      }
   }
   if (invalid) return 0;
   for (int i = 0; i < n; i++) {
      Turtle turtle;
      for (int j = 0; j < result[i].size(); j++) {
         char c = toupper(result[i][j]);
         switch (c) {
         case 'F':
            turtle.f();
            break;
         case 'B':
            turtle.b();
            break;
         case 'L':
            turtle.l();
            break;
         case 'R':
            turtle.r();
            break;
         }
      }
      cout << (turtle.maxX - turtle.minX) * (turtle.maxY - turtle.minY) << endl;
   }
   return 0;
}