class BSTVertex:
    def init(self, key=None):
        self.key = key
        self.left = None
        self.right = None

class BST:
    def init(self):
        self.root = None
        self.n = 0

    def insert(self, v):
        self.root = self._insert(self.root, v)

    def _insert(self, T, v):
        if T is None:
            self.n += 1
            return BSTVertex(v)
        
        if T.key < v:
            T.right = self._insert(T.right, v)
        elif T.key > v:
            T.left = self._insert(T.left, v)
        
        return T

    def inorder(self):
        self._inorder(self.root)
        print()

    def _inorder(self, T):
        if T is None:
            return

        self._inorder(T.left)
        print(T.key, end=' ')
        self._inorder(T.right)

    def preorder(self):
        self._preorder(self.root)
        print()

    def _preorder(self, T):
        if T is None:
            return

        print(T.key, end=' ')
        self._preorder(T.left)
        self._preorder(T.right)

    def findMin(self):
        return self._findMin(self.root)

    def _findMin(self, T):
        if T is None:
            return None
        
        while T.left is not None:
            T = T.left
        
        return T.key

    def findMax(self):
        return self._findMax(self.root)

    def _findMax(self, T):
        if T is None:
            return None
        
        while T.right is not None:
            T = T.right
        
        return T.key

    def search(self, v):
        res = self._search(self.root, v)
        return res.key if res is not None else -1

    def _search(self, T, v):
        if T is None or T.key == v:
            return T
        
        if T.key < v:
            return self._search(T.right, v)
        else:
            return self._search(T.left, v)

    def successor(self, v):
        vPos = self._search(self.root, v)
        return self._successor(vPos) if vPos is not None else -1

    def _successor(self, T):
        if T is None:
            return None

        if T.right is not None:
            return self._findMin(T.right)

        parent = T.parent
        while parent is not None and T == parent.right:
            T = parent
            parent = parent.parent

        return parent.key if parent is not None else -1

    def predecessor(self, v):
        vPos = self._search(self.root, v)
        return self._predecessor(vPos) if vPos is not None else -1

    def _predecessor(self, T):
        if T is None:
            return None

        if T.left is not None:
            return self._findMax(T.left)

        parent = T.parent
        while parent is not None and T == parent.left:
            T = parent
            parent = parent.parent

        return parent.key if parent is not None else -1

    def remove(self, v):
        self.root = self._remove(self.root, v)

    def _remove(self, T, v):
        if T is None:
            return None
        
        if T.key == v:
            if T.left is None and T.right is None:
                del T
                self.n -= 1
                T = None
            #elif T.left
