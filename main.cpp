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
using namespace std;
using namespace binaryMethod;




int main() {

    Dense::DenseGraph dg1(10, false);
    ReadGraph<Dense::DenseGraph> rdg1(dg1, "/Users/pool_little/GitHub/Algorithm_Cpp/GraphTest_doc");
    dg1.show();

    cout<<"#########################################"<<endl;

    Sparse::SparseGraph sg1(10, false);
    ReadGraph<Sparse::SparseGraph> rsg1(sg1,"/Users/pool_little/GitHub/Algorithm_Cpp/GraphTest_doc");
    sg1.show();

}