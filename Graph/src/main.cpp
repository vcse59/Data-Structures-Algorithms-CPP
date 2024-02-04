#include <iostream>
#include <list>
#include <unordered_map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <string>
#include <sstream>

using namespace std;

template<class T>
class Graph
{
    public:
        Graph(){}
        ~Graph(){}

        void addEdgeDirectedGrpah(T from, T to);
        void addEdgeUnDirectedGraph(T from, T to);
        void dfsTraversal(T startNode = -1);
        void breadthFirstSearch();
        void bfsTraversal(T startNode = -1);
        void topologicalSort();
        void clearVisitedNodes();
        bool detectCycle();
        string shortestPathUnDirectedGraphWeightOne(T origin, T destination);
        
    private: 
        void dfsToplogicalSort(T v, unordered_set<T>& topSortOrder);
        tuple<T>* cycleDetection(unordered_set<T>& visitedNode, T currentNode, T& startNode);
        unordered_map<T, list<T>> adj;
        unordered_set<T> m_visitedNode;
};

template<class T>
void Graph<T>::addEdgeDirectedGrpah(T from, T to)
{
    typename unordered_map<T, list<T>>::iterator it = adj.find(from);
    if (it != adj.end())
    {
        list<T>& listContainer = it->second;
        listContainer.push_back(to);
    }
    else{
        list<T> container;
        container.push_back(to);
        adj.insert(pair<T, list<T>>(from, container));
    }
}

template<class T>
void Graph<T>::addEdgeUnDirectedGraph(T from, T to)
{
    addEdgeDirectedGrpah(from, to);
    addEdgeDirectedGrpah(to, from);
}

template<class T>
void Graph<T>::dfsTraversal(T startNode)
{
    if (startNode == -1)
    {
        typename unordered_map<T, list<T>>::iterator it = adj.begin();
        startNode = it->first;
    }

    m_visitedNode.insert(startNode);
    cout << startNode << " ";
 
    for (auto iter = adj[startNode].begin(); iter != adj[startNode].end(); iter++)
    {
        if (m_visitedNode.find(*iter) == m_visitedNode.end())
        {
            dfsTraversal(*iter);
        }
    }
}

template<class T>
void Graph<T>::breadthFirstSearch()
{
    cout << "Breadth First Search : " ;
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        if (m_visitedNode.find(it->first) == m_visitedNode.end())
            bfsTraversal(it->first);
    }
    cout << endl;
}

template<class T>
void Graph<T>::bfsTraversal(T startNode)
{
    queue<T> cont;

    cont.push(startNode);
    m_visitedNode.insert(startNode);

    while(!cont.empty())
    {
        T node = cont.front();
        cout << node << " ";
        cont.pop();
        

        for (auto it = adj[node].begin(); it != adj[node].end(); it++)
        {
            if (m_visitedNode.find(*it) == m_visitedNode.end()){
                m_visitedNode.insert(*it);
                cont.push(*it);
            }
        }
    }
}

template<class T>
void Graph<T>::dfsToplogicalSort(T v, unordered_set<T>& topSortOrder)
{
    if (topSortOrder.find(v) == topSortOrder.end())
    {        
        topSortOrder.insert(v);
        for(auto it = adj[v].begin(); it != adj[v].end(); it++)
        {
            if (topSortOrder.find(v) == topSortOrder.end())
            {
                dfsToplogicalSort(*it, topSortOrder);
            }
        }
    }
}

template<class T>
void Graph<T>::topologicalSort()
{
    unordered_set<T> topSortOrder;

    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        dfsToplogicalSort(it->first, topSortOrder);
    }

    cout << "Topological Sort is : ";
    for (auto it = topSortOrder.begin(); it != topSortOrder.end(); it++)
    {
        cout << *it << " ";
    }
}

template<class T>
void Graph<T>::clearVisitedNodes()
{
    m_visitedNode.clear();
}

template<class T>
tuple<T>* Graph<T>::cycleDetection(unordered_set<T>& visitedNode, T currentNode, T& startNode)
{
    tuple<T> * tupleOutput = nullptr;

    visitedNode.insert(currentNode);

    for (auto it = adj[currentNode].begin(); it != adj[currentNode].end(); it++)
    {
        if (visitedNode.find(*it) == visitedNode.end())
        {
            tupleOutput = cycleDetection(visitedNode, *it, startNode);
            if (tupleOutput != nullptr)
            {
                break;
            }
        }
        else
        {
            if (startNode == *it)
            {
                return new tuple<T>(startNode);
            }
        }
    }

    return tupleOutput;
}

template<class T>
bool Graph<T>::detectCycle()
{
    for (auto it = adj.begin(); it != adj.end(); it++)
    {
        unordered_set<T> visitedNode;
        T startNode = it->first;
        tuple<T>* tupleOutput = cycleDetection(visitedNode, it->first, startNode);
        //cout << "Start Node : " << it->first << endl;
        if (tupleOutput != nullptr)
        {
            cout << "Cycle is detected from for Edges from : " << std::get<0>(*tupleOutput) << endl;

            cout << "Detected loop is : ";
            for (auto iter = visitedNode.begin(); iter != visitedNode.end(); iter++)
            {
                cout << *iter << " ";
            }
            delete tupleOutput;
            return true;
        }
    }
    return false;
}

template<class T>
string Graph<T>::shortestPathUnDirectedGraphWeightOne(T origin, T destination)
{
    queue<T> queueCont;
    unordered_map<T, T> mapShortPath;
    unordered_map<T, int> mapShortDistance;

    queueCont.push(origin);
    m_visitedNode.insert(origin);
    mapShortPath.insert(pair<T, T>(origin, origin));
    mapShortDistance.insert(pair<T, int> (origin, 0));
    
    while(!queueCont.empty())
    {
        T item = queueCont.front();
        queueCont.pop();

        for (auto it = adj[item].begin(); it != adj[item].end(); it++){

            if (m_visitedNode.find(*it) == m_visitedNode.end()){
                
                mapShortPath.insert(pair<T, T>(*it, item));
                typename unordered_map<T, int>::iterator iter = mapShortDistance.find(item);
                mapShortDistance.insert(pair<T, int>(*it, (iter->second + 1 )));

                m_visitedNode.insert(*it);
                queueCont.push(*it);
            }
        }
    }
    
    string path;

    typename unordered_map<T,T>::iterator it = mapShortPath.find(destination);
    while(it != mapShortPath.end())
    {
        stringstream os;
        os << " " << it->first;
        path = os.str() + path;
        if (it->first == origin)
            it = mapShortPath.end();
        else{
                it = mapShortPath.find(it->second);
            } 
    }
    return path;
}


int main(int argc, char *argv[])
{
    cout << endl << endl << "**************Graph 1 Operations****************" << endl << endl;

    Graph<int> g1;
    g1.addEdgeDirectedGrpah(7, 11);
    g1.addEdgeDirectedGrpah(7, 8);
    g1.addEdgeDirectedGrpah(5, 11);
    g1.addEdgeDirectedGrpah(3, 8);
    g1.addEdgeDirectedGrpah(3, 10);
    g1.addEdgeDirectedGrpah(11, 2);
    g1.addEdgeDirectedGrpah(11, 9);
    g1.addEdgeDirectedGrpah(11, 10);
    g1.addEdgeDirectedGrpah(8, 9);

    // Cycle Detection introduced
    //g.addEdge(9, 3);
    //g.addEdge(9, 11);

    int startNode = 7;
    cout << "Depth first traversal from vertex " << startNode << " is : ";
    g1.dfsTraversal(startNode);
    cout << endl;
    g1.clearVisitedNodes();
    g1.breadthFirstSearch();
    g1.clearVisitedNodes();
    cout << "Depth first traversal from vertex " << startNode << " is : ";
    g1.bfsTraversal(startNode);
    cout << endl;
    g1.clearVisitedNodes();
    if (!g1.detectCycle())
    {
        g1.clearVisitedNodes();
        g1.topologicalSort();
    }
    cout << endl;

    cout << endl << endl << "**************Graph 2 Operations****************" << endl << endl;

    Graph<int> g2;
    g2.addEdgeDirectedGrpah(1, 2);
    g2.addEdgeDirectedGrpah(2, 3);
    g2.addEdgeDirectedGrpah(3, 1);
    if (!g2.detectCycle())
    {
        g2.clearVisitedNodes();
        g2.topologicalSort();
    }
    cout << endl;
    startNode = 2;
    cout << "Depth first traversal from vertex " << startNode << " is : ";
    g2.dfsTraversal(startNode);
    g2.clearVisitedNodes();
    cout << endl;


    startNode = 2;
    cout << "Breadth First Traversal from vertex " << startNode << " is : ";
    g2.bfsTraversal(startNode);
    g2.clearVisitedNodes();
    cout << endl;

    if (!g2.detectCycle())
    {
        g2.clearVisitedNodes();
        g2.topologicalSort();
    }

    cout << endl << endl << "**************Graph 3 Operations****************" << endl << endl;

    Graph<char> g3;
    g3.addEdgeDirectedGrpah('A', 'B');
    g3.addEdgeDirectedGrpah('A', 'C');
    g3.addEdgeDirectedGrpah('B', 'D');
    g3.addEdgeDirectedGrpah('B', 'E');
    g3.addEdgeDirectedGrpah('C', 'F');
    g3.addEdgeDirectedGrpah('C', 'G');

    char charNode = 'A';
    cout << "Breadth First Traversal from vertex " << charNode << " is : ";
    g3.bfsTraversal(charNode);
    cout << endl;
    g3.clearVisitedNodes();
    cout << "Depth First Traversal from vertex " << charNode << " is : ";
    g3.dfsTraversal(charNode);
    cout << endl;

    cout << endl << endl << "**************Graph 4 Operations****************" << endl << endl;

    Graph<char> g4;
    g4.addEdgeUnDirectedGraph('A', 'B');
    g4.addEdgeUnDirectedGraph('A', 'C');
    g4.addEdgeUnDirectedGraph('A', 'D');
    g4.addEdgeUnDirectedGraph('B', 'C');
    g4.addEdgeUnDirectedGraph('C', 'D');
    g4.addEdgeUnDirectedGraph('D', 'E');
    g4.addEdgeUnDirectedGraph('D', 'F');
    g4.addEdgeUnDirectedGraph('F', 'E');
    g4.addEdgeUnDirectedGraph('F', 'G');
    g4.addEdgeUnDirectedGraph('G', 'H');
    g4.addEdgeUnDirectedGraph('H', 'I');
    g4.addEdgeUnDirectedGraph('H', 'J');

    cout << "Breadth First Traversal from Vertex A : ";
    g4.bfsTraversal('A');
    cout << endl;
    g4.clearVisitedNodes();
    string shortPath = g4.shortestPathUnDirectedGraphWeightOne('A', 'I');
    cout << "Shortest Path from A to I is " << shortPath << endl;

    return 0;
} 
