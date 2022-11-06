#include <iostream>
#include <vector>
using namespace std;

//PODS
struct Pixel {
	int x,y;
};

void image_search(unsigned char *data, int width, int height) {
	vector<Pixel> blues; //YOU: Fill this vector with all the blue pixels, maybe 
	int count = 0;	

	//A for-loop checking for the colors (red, green, blue) in the image
	for (int i = 0; i < 3; i++) { //For every color (3 colors)
		/*
		if (i == 0) cout << "Red:\n";
		else if (i == 1) cout << "Green:\n";
		else cout << "Blue\n";
		*/
		for (int k = 0; k < height; k++) { //Rows
			for (int j = 0; j < width; j++) { //Columns
				//cout << (int)data[j + k*width + i*height*width] << " "; 
				Pixel temp = {j,k};
				//Obtaining color brightness at location (x,y) and outputting the color value. 
				/*
				int red = (int)data[j + k*width]; 
				int green = (int)data[j + k*width + i*height*width]; 
				int blue = (int)data[j + k*width + i*height*width]; 
				*/

				//if (red < 20 and green < 20 and blue > 235 and blue <= 255) 
				
				if (i == 2 and (int)data[j + k*width + i*height*width] > 235 and (int)data[j + k*width] < 20 and (int)data[j + k*width + height*width] < 20) { 
					//cout << "Blue pixels found\n";
					//blues.push_back({j,k});
					blues.push_back(temp);
					count++;
				};
				
			}
			cout << endl;
		} 
	}
	//YOU: Average all the x values from blues together into an int x
		long x = 0; //Was previously a double
	
	//YOU: Average all the y values from blues together into an int y
		long y = 0; //Was previously a double

		for (int i = 0; i < blues.size(); i++) {
			x += blues.at(i).x;
			y += blues.at(i).y;
		}

		x = x / blues.size();
		y = y / blues.size();
	//Then we print the result and are done

	if (count == 0) cout << "No blue found.\n";
	else cout << "The center point for blue in this image is: (" << x << "," << y << ")\n";
}
