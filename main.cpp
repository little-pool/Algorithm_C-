#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"
#include "Sort.h"
#include "Heap.h"
#include "binarySearch.h"
#include <queue>
#include "Union.h"
#include "Graph.h"
#include "ReadGraph.h"
#include "Component.h"
#include "Path.h"
#include "ShortestPath.h"
#include "WeightGraph.h"
using namespace std;
using namespace binaryMethod;




int main() {

    Dense::DenseGraph dg1(10, false);
    ReadGraph<Dense::DenseGraph> rdg1(dg1, "/Users/pool_little/GitHub/Algorithm_Cpp/GraphTest_doc");
    Component<Dense::DenseGraph> comDen1(dg1);
    Path<Dense::DenseGraph> pathDen1(dg1, 0);
    ShortestPath<Dense::DenseGraph> spathDen1(dg1, 0);

    dg1.show();
    cout<<"Components:"<<comDen1.GetComponentNum();
    cout<<endl;
    pathDen1.PathPrint(9);
    spathDen1.PathPrint(9);

    //测试from
    for(int i = 0 ; i < 10 ; i ++){
        cout<<pathDen1.GetFrom()[i]<<" ";
    }

    cout<<endl;
    cout<<"#########################################"<<endl;

    Sparse::SparseGraph sg1(10, false);
    ReadGraph<Sparse::SparseGraph> rsg1(sg1,"/Users/pool_little/GitHub/Algorithm_Cpp/GraphTest_doc");
    Component<Sparse::SparseGraph> comSpar1(sg1);
    Path<Sparse::SparseGraph>pathSparse1(sg1, 0);
    sg1.show();
    cout<<"Components:"<<comSpar1.GetComponentNum();
    cout<<endl;
    cout<<"#########################################"<<endl;


    DenseGraph_wt<double > dg2(10,false);
    ReadGraph_wt<double, DenseGraph_wt<double>> rdg2(dg2, "/Users/pool_little/GitHub/Algorithm_Cpp/GraphTest_doc_wt");
    dg2.printGraph();





}