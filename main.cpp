#include <iostream>
#include <sstream>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <queue>
#include "mygraph.cpp"
using namespace std;

template <class Container>
void split1(const string& str, Container& cont)
{
    istringstream iss(str);
    copy(istream_iterator<string>(iss),
         istream_iterator<string>(),
         back_inserter(cont));
}
int findmin(vertex &vertex1)
{
    int size=vertex1.edges.size();
    int min=vertex1.edges[0].length, minadress=0;
    for(int i=0; i<size; i++)
    {
        if(vertex1.edges[i].length<=min)
        {
            min=vertex1.edges[0].length;
            minadress=i;
        }
    }
    return minadress;

}
int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project3 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;
    ifstream infile(argv[1]);

    ofstream myfile;
    myfile.open(argv[2]);
    string line;
    getline(infile, line);
    vector<string> words;
    split1(line, words);
    int numberofcity = stoi(words[0]);
    cout << "number of cities : " << numberofcity << endl;
    int numberofedge = stoi(words[1]);
    cout << "number of edges : " << numberofedge << endl;
    int numberofthief = stoi(words[2]);
    cout << "number of thieves : " << numberofthief << endl;
    int numberofjeweler = stoi(words[3]);
    cout << "number of jewelers : " << numberofjeweler << endl;


    vector<vertex> vertices(numberofcity+1);

    for(int i=0; i<=numberofcity; i++)
        vertices[i]=vertex();


    for(int i=0; i<numberofjeweler; i++)
    {
        vector<string> words1;
        getline(infile, line);
        split1(line,words1);
        vertices[stoi(words1[0])].jeweler=stoi(words1[1]);
        for(int j=0; j<stoi(words1[1]); j++)
        {
            vertices[stoi(words1[0])].jewelers.push_back(stoi(words1[2+j]));
        }

    }
    edge edge1,edge2;
    for(int i=0; i<numberofedge; i++) {
        vector<string> words2;
        getline(infile, line);
        split1(line, words2);
        if (stoi(words2[3]) == 0) {
            edge1 = edge(stoi(words2[0]), stoi(words2[1]), stoi(words2[2]), 0);
            vertices[stoi(words2[0])].edges.push_back(edge1);
        }else
        {
            vector<int> th;
            for(int j=0; j<stoi(words2[3]); j++)
            {
                th.push_back(stoi(words2[4+j]));
            }
            edge2=edge(stoi(words2[0]),stoi(words2[1]),stoi(words2[2]),stoi(words2[3]),th);
            vertices[stoi(words2[0])].edges.push_back(edge2);

        }
    }

    int current=1,min,coinsmatch=0;
    string result="";
    vector<int> results;
    results.push_back(1);
    vector<int> currentjewelers;
    while(current!=numberofcity)
    {
       if(vertices[current].edges.size()==0) {

           result="-1";
           break;
       }

           if (vertices[current].jeweler != 0) {
               for (int i = 0; i < vertices[current].jeweler; i++) {
                   currentjewelers.push_back(vertices[current].jewelers[i]);
               }
           }
            min=findmin(vertices[current]);
           cout << current << min << endl;
           cout << vertices[current].edges[min].pre << vertices[current].edges[min].next
                << vertices[current].edges[min].thiefnumber << endl;
           if (vertices[current].edges[min].thiefnumber == 0) {
               cout << "evet";
               current = vertices[current].edges[min].next;
               cout << current << endl;
               results.push_back(current);


           } else if (currentjewelers.size() != 0) {
               for (int i = 0; i < vertices[current].edges[min].thiefnumber; i++) {
                   if (find(currentjewelers.begin(), currentjewelers.end(), vertices[current].edges[min].thiefs[i]) !=
                       currentjewelers.end()) {
                       coinsmatch++;
                   }
               }
               if (coinsmatch == vertices[current].edges[min].thiefnumber) {

                   current = vertices[current].edges[min].next;
                   results.push_back(current);
                   cout << "ci" << current << endl;

               }
               coinsmatch = 0;
           } else {
               vertices[current].edges.erase(vertices[current].edges.begin() + min);
           }

    }
    if(result=="-1")
        myfile<<result;
    else {
        for(int i=0; i<results.size(); i++)
            myfile<<results[i]<<" ";
    }
    myfile.close();
    return 0;
}