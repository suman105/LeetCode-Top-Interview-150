class Solution {
public:
    unordered_map<Node*, Node*> cloneMap;  // Maps original node to cloned node

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;
        
        // If node is already cloned, return its copy
        if (cloneMap.find(node) != cloneMap.end()) {
            return cloneMap[node];
        }

        // Create a new node
        Node* clonedNode = new Node(node->val);
        cloneMap[node] = clonedNode;  // Store mapping

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            clonedNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return clonedNode;
    }
};
