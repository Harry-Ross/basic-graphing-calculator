// Graphing Calculator.cpp : Defines the entry point for the application.
//

#include "headers.hpp"

#include "bmpFunctions.hpp"

using namespace std;

int main() {	
	fstream file;
	file.open("C:\\Users\\Harry\ Ross\\Documents\\Code\\C++\\Graphing\ Calculator\\Graphing\ Calculator\\graph.bmp", ios::out | ios::binary | ios::trunc);

	BMPFunctions bmpFunctions;
	if (!file) {
		cerr << "File was unable to be opened." << endl;
	}
	if (file.is_open()) {
		bmpFunctions.writeBMPHeader(file);
		for (int x = 0; x < 1024; x++) {
			for (int y = 0; y < 1024; y++) {
				if (x == y) {
					bmpFunctions.writePixel(file, { 255, 255, 255 });
				}
				else {
					bmpFunctions.writePixel(file, { 0, 0, 0 });
				}
				
			}
		}
	}
	file.close();
	
	return 0;
}