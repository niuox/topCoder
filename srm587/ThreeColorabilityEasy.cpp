
//Problem:http://community.topcoder.com/stat?c=problem_statement&pm=12699&rd=15699
//Analysis:http://apps.topcoder.com/wiki/display/tc/SRM+587
/*
use row-major order to visit every rectangle of this problem using the mind that a rectangle is
consist of two triangles and try to find out the contradiction of that there must be three different
colors in a triangle.
*/
class ThreeColorabilityEasy {
public:
	string isColorable(vector <string> cells) {	
	
	int h = cells.size();
	int w = cells[0].size();
	int color[h+1][w+1];
	memset(color,-1,sizeof(color));

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			int &a = color[i][j];int &b = color[i][j+1];
			int &c = color[i+1][j+1];int &d = color[i+1][j];

			if(cells[i][j] == 'N')
			{
				if(a == -1 && b == -1 && c == -1 && d == -1)
				{
					a = 0;b = d = 1;c = 2;
				}
				else if(b!=-1 && d!=-1) 
				{
					c = 3 - a - b;
					if(c == d) return "No";
				}
				else if(b!=-1)
				{
					c = 3 - a - b;
					d = 3 - a - c;
				}
				else if(d!=-1)
				{
					c = 3 - a - d;
					b = 3 - a - c;
				}
			}
			else
			{
				if(a == -1 && b == -1 && c == -1 && d == -1)
				{
					a = c = 0;b = 1;d = 2;
				}
				else if(b!=-1 && d!=-1)
				{
					if(b == d) return "No";
					c = 3 - b - d;
				}
				else if(b!=-1)
				{
					d = 3 - a - b;
					c = 3 - b - d;
				}
				else if(d!=-1)
				{
					b = 3 - a - d;
					c = 3 - b - d;
				}
			}
		}
	}
	return "Yes";
	}
};
