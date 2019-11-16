#include <iostream>





using namespace std;


void MakeDungeon(int width, int height)
{
    char shape[(height * width)];

    for(int x = 0; x < height; x++)
		for (int y = 0; y < width; y++)
			shape[(x * width) + y] = ' ';

    for(int x = 0; x < height; x = x + (height-1))
		for(int y = 0; y < width; y++)
			  shape[(x * width) + y] = '*';

	for(int x = 1; x < (height - 1); x++)
		for(int y = 0; y < width; y = y + (width-1))
			shape[(x * width) + y] = '*';

    for(int i = 0; i<height; i++){
		cout<<endl;
		for(int j = 0; j<width; j++){
			cout<<shape[(i * width) + j];
		}
	}
}


int main ()
{
    int width=0;
    int height=0;
    cout<< "the width of dungeon is: ";
    cin>>width;
    cout<< "the height of dungeon is: ";
    cin>>height;
    if((width < 8) || (height < 8))
    {
        height = 8;
        width=8;
        cout<< "Invalid values entered. Making a 8x8 one.";
    }


    //char shape[(height * width) + height];
    MakeDungeon(width,height);
    return 0;

}






