#include "headers.hpp"

using namespace std;

constexpr int pixel_size = 3;

constexpr int width = 1024;
constexpr int height = 1024;

constexpr int offset = 54;

struct pixel {
	int red;
	int green;
	int blue;
};

typedef struct pixel Pixel;

class BMPFunctions {
public:
	void writeBMPHeader(fstream& file) {
		if (file.is_open()) {
			int size = 1024 * 1024 * 3 + offset;
			stringstream ss;
			ss << "0x" << hex << size << endl;
			string result(ss.str());
			const char* input =  result.c_str();
			cout << input << endl;
			char stream[2] = { 0x4d, 0x42 };
			file.write(stream, sizeof(stream));
			file.write(input, 4);
		}
	}

	void writePixel(fstream& file, Pixel pixel) {
		if (file.is_open()) {

		}
	}
};

