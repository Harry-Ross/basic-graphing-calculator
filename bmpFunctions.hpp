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
			int size = (1024 * 1024 * 3) + offset;
			cout << size << endl;
			/*stringstream ss;
			ss << "0x" << hex << size << endl;
			string result(ss.str());
			const char* input =  result.c_str();
			cout << input << endl;*/
			char signature[2] = { 0x42, 0x4d };
			file.write(signature, sizeof(signature));

			//char sizeInput[4] = { 0, 0x30, 0, 0x36 };
			file.write((char*)&size, 4);

			char reserved[4] = {0};
			file.write(reserved, sizeof(reserved));

			//char offsetInput[4] = { offset };
			file.write((char*)&offset, 4);

			char bitmapInfoHeader[4] = { 40 };
			file.write(bitmapInfoHeader, sizeof(bitmapInfoHeader));

			//char widthInput[4] = { width };
			file.write((char*)&width, 4);

			//char heightInput[4] = { height };
			file.write((char*)&height, 4);

			char planes[2] = { 1 };
			file.write(planes, sizeof(planes));

			char bitsPerPixel[2] = { 24 };
			file.write(bitsPerPixel, sizeof(bitsPerPixel));

			char compression[4] = {0, 0, 0, 0 };
			file.write(compression, sizeof(compression));

			char sizeImageData[4] = { width * height * 3 };
			file.write(sizeImageData, sizeof(sizeImageData));

			int pixelPerMetre = 2835;
			file.write((char*)&pixelPerMetre, 4);
			file.write((char*)&pixelPerMetre, 4);

			char coloursInRange[4] = { 0 };
			file.write(coloursInRange, sizeof(coloursInRange));
			file.write(coloursInRange, sizeof(coloursInRange));
		}
	}

	void writePixel(fstream& file, Pixel pixel) {
		if (file.is_open()) {
			char buffer[3] = { pixel.red, pixel.green, pixel.blue };
			file.write(buffer, sizeof(buffer));
		}
	}
};

