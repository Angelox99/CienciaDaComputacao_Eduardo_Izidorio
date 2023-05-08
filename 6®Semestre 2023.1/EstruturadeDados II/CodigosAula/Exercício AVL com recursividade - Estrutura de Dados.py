# Autor(a): Marcia Gabrielle Bonifácio de Oliveira
# matrícula: 2020011319
# DCC 405 - Estrutura de Dados II - Prof. Acauan

class Node:

    def __init__(self, value): 
        self.value = value
        self.leftChild = None
        self.rightChild = None


class Tree:
    
    def __init__(self, root = None): 
        self.root = None if root is None else Node(root)


    def insert(self, value, node = 'root'): 
        if node == 'root': node = self.root
        
        if self.root is None: 
            self.root = Node(value)
            return 

        if node is None: return Node(value)
        
        if value < node.value: node.leftChild = self.insert(value, node.leftChild)
        elif value > node.value: node.rightChild = self.insert(value, node.rightChild)
        
        return self.tree_rotate(node)



    def delete(self, value, node = 'root'): 
        if node == 'root': node = self.root

        if not node: return node

        if value < node.value: node.leftChild = self.delete(value, node.leftChild)
        elif value > node.value: node.rightChild = self.delete(value, node.rightChild)
        else:

            if node.leftChild is None:
                temp = node.rightChild
                node = None
                return temp
            if node.rightChild is None:
                temp = node.leftChild
                node = None
                return temp
            
            temp = self.find_min(node.rightChild)
            node.value = temp.value
            node.rightChild = self.delete(temp.value, node.rightChild)
        
        return self.tree_rotate(node)



    def find_min(self, node = None): 
        if self.root is None: return None
        
        if node is None: node = self.root

        if node.leftChild is not None: return self.find_min(node.leftChild)
        return node



    def find_max(self, node = None): 
        if self.root is None: return None
        
        if node is None: node = self.root
        
        if node.rightChild is not None: return self.find_max(node.rightChild)
        return node
    


    def find_pred(self, value, node, pred = None): 
        if not node: return pred

        if node.value == value:
            if node.leftChild:
                return self.find_max(node.leftChild)

        elif value < node.value:
            return self.find_pred(value, node.leftChild, pred)

        else:
            pred = node
            return self.find_pred(value, node.rightChild, pred)

        return pred
    


    def find_succ(self, value, node, succ = None): 
        if not node: return succ
    
        if node.value == value:
            if node.rightChild:
                return self.find_min(node.rightChild)
            
        elif value < node.value:
            succ = node
            return self.find_succ(value, node.leftChild, succ)
    
        else:
            return self.find_succ(value, node.rightChild, succ)
    
        return succ



    def search(self, value, node = None): 
        if node is None: node = self.root

        if node.value == value: return node

        if value < node.value: return self.search(value, node.leftChild) if node.leftChild is not None else None
        
        return self.search(value, node.rightChild) if node.rightChild is not None else None


    
    def print_tree_preorder(self, node): 
        if not node: return

        print(node.value)
        self.print_tree_preorder(node.leftChild) 
        self.print_tree_preorder(node.rightChild)   
    

    
    def print_tree_inorder(self, node): 
        if not node: return
        
        self.print_tree_inorder(node.leftChild) 
        print(node.value)
        self.print_tree_inorder(node.rightChild)   
    

    
    def print_tree_posorder(self, node): 
        if not node: return

        self.print_tree_preorder(node.leftChild) 
        self.print_tree_preorder(node.rightChild)   
        print(node.value)


        
    def node_height(self, node): 
        return 0 if not node else max(self.node_height(node.leftChild), self.node_height(node.rightChild)) + 1
        

        
    def node_balance(self, node): 
        return self.node_height(node.leftChild) - self.node_height(node.rightChild)
    

    
    def sub_tree_rotate_r(self, node): 
        if not node: return
            
        temp_new_root = node.leftChild

        node.leftChild, temp_new_root.rightChild = temp_new_root.rightChild, node

        if node == self.root: self.root = temp_new_root

        return temp_new_root
    
    

    def sub_tree_rotate_l(self, node): 
        if not node: return
            
        temp_new_root = node.rightChild

        node.rightChild, temp_new_root.leftChild = temp_new_root.leftChild, node

        if node == self.root: self.root = temp_new_root

        return temp_new_root


       
    def sub_tree_rotate_dr(self, node): 
        node.leftChild = self.sub_tree_rotate_l(node.leftChild)
        return self.sub_tree_rotate_r(node)
            
       

    def sub_tree_rotate_dl(self, node): 
        node.rightChild = self.sub_tree_rotate_r(node.rightChild)
        return self.sub_tree_rotate_l(node)
    
    
    
    def tree_rotate(self, node): 
        if not node: return

        match self.node_balance(node):
            case 2:
                match self.node_balance(node.leftChild):
                    case 1|0:
                        return self.sub_tree_rotate_r(node)
                    case -1:
                        return self.sub_tree_rotate_dr(node)
            case -2:
                match self.node_balance(node.rightChild):
                    case -1|0:
                        return self.sub_tree_rotate_l(node)
                    case 1:
                        return self.sub_tree_rotate_dl(node)
        
        return node
                        
