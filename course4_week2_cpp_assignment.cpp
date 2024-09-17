#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;

// We need to create a hex graph class
// Variation of the graph class
class Hex{
    private:
        int hex_dimension;
        unordered_map<pair<int , int> , char> nodes;
        unordered_map< pair<int , int>, pair<int , int> > edges;

    public:
        //Constructor
        Hex(int hex_dimension) : hex_dimension(hex_dimension) {
            // initialise the nodes
            for (int i = 0; i < hex_dimension; i++) {
                for (int j = 0; j < hex_dimension; j++) {
                    nodes[{i, j}] = '.';
                }
            }

            // initialise the edges
            for (int i = 0; i < hex_dimension; i++) {
                for (int j = 0; j < hex_dimension; j++) {
                    if (i < hex_dimension - 1) {
                        edges[{i, j}] = {i + 1, j};
                    }
                    if (j < hex_dimension - 1) {
                        edges[{i, j}] = {i, j + 1};
                    }
                    if (i < hex_dimension - 1 && j < hex_dimension - 1) {
                        edges[{i, j}] = {i + 1, j + 1};
                    }
                }
            }
        }

        //Method to add a node to a graph
        void addNode() {
            // add a node to the node_list with an additional number
            nodes[number_of_nodes()] = numeric_limits<double>::infinity();
        }

        //Method to find the number of nodes in your graph
        int number_of_nodes() {
            return nodes.size();
        }

        void addEdge(int node1, int node2) {
            if (node1 >= number_of_nodes() || node2 >= number_of_nodes()) {
                return;
            } else if (node1 == node2) {
                return;
            } else {
                // Assuming the graph is undirected
                edges[make_pair(node1,node2)] = numeric_limits<double>::infinity();
                edges[make_pair(node2,node1)] = numeric_limits<double>::infinity();
            }
        }

        // Method to check if two nodes are adjacent
        bool isAdjacent(int node1, int node2) {
            return edges.find(make_pair(node1, node2)) != edges.end() ||
                edges.find(make_pair(node2, node1)) != edges.end();
        }

        //Method to set the weight of an edge
        void set_edge_weight(int node1, int node2, double weight) {
            if (node1 >= number_of_nodes() || node2 >= number_of_nodes()) {
                return;
            }
            if (node1 == node2) {
                return;
            }
            // Set the weight for both directions if the graph is undirected
            edges[make_pair(node1, node2)] = weight;
            edges[make_pair(node2, node1)] = weight;
        }

        //Method to get the weight of an edge
        double get_edge_weight(int node1, int node2) {
            return edges[make_pair(node1,node2)];
        }

        //Method to set the value of a node
        void set_node_value(int node, double value) {
            nodes[node] = value;
        }

        //Method to get the value of a node
        double get_node_value(int node) {
            return nodes[node];
        }

        // Method to get the adjacent nodes
        vector<int> get_adjacent_nodes(int node) {
            vector<int> adjacent;
            for (auto& edge : edges) {
                if (edge.first.first == node) adjacent.push_back(edge.first.second);
            }
            return adjacent;
        }
    
        
};

int main() {

    // We want to generate a hex board


    

    return 0;
    }