#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
#include <chrono>
#include <thread>
#include "gfx.h"
#include "point.h"
#include "worm.h"
using namespace std;

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

int main(int argc, char* argv[]) {
	if (argc < 2) {
		cout << "Usage: animacion [number of worms]\n";
		return 0;
	}
	int n = stoi(argv[1]);
	int w = 1024, h = 768;
	gfx_open(w, h, "Worms");

	vector<Worm> worms;

	int sz = 40;
	vector<deque<Point>> samples(n, deque<Point>(sz));
	for (int i = 0; i < n; ++i) {
		worms.emplace_back(Worm::aleatorio(100, 1000) * M_PI);
		for (int j = 0; j < sz; ++j) {
			samples[i][j] = worms[i].getNextPoint();
		}
	}

	while (true) {
		gfx_clear();
		for (int i = 0; i < n; ++i) {
			gfx_color(worms[i].getR(), worms[i].getG(), worms[i].getB());
			for (int j = 0; j < sz; ++j) {
				int x = int(samples[i][j].getX()) % w;
				int y = int(samples[i][j].getY()) % h;
				if (x < 0) x += w;
				if (y < 0) y += h;
				gfx_point(x, y);
			}
			samples[i].pop_front();
			samples[i].push_back(worms[i].getNextPoint());
		}
		gfx_flush();
		std::this_thread::sleep_for(std::chrono::microseconds(1000000 / 100));
	}
	return 0;
}
