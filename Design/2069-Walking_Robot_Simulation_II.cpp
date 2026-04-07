class Robot {
public:
    int w,h,x,y,dir,perimeter;
    vector<pair<int,int>> directions={{1,0},{0,1},{-1,0},{0,-1}};
    vector<string> dirNames={"East","North","West","South"};
    Robot(int width,int height)
    {
        w=width;
        h=height;
        x=0;
        y=0;
        dir=0;
        perimeter=2*(w+h-2);
    }
    void step(int num)
    {
        if(perimeter==0)
        {
            return;
        }
        num%=perimeter;
        if(num==0)
        {
            num=perimeter;
        }
        while(num--)
        {
            int nx=x+directions[dir].first,ny=y+directions[dir].second;
            if(nx<0 || nx>=w || ny<0 || ny>=h)
            {
                dir=(dir+1)%4;
                nx=x+directions[dir].first;
                ny=y+directions[dir].second;
            }
            x=nx;
            y=ny;
        }
    }
    vector<int> getPos()
    {
        return {x,y};
    }
    string getDir()
    {
        return dirNames[dir];
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
