from binarySearchTree import *
    
bst1 = BinarySearchTree()
bst1.insert(55)
bst1.insert(15)
bst1.insert(60)
bst1.insert(8)
bst1.insert(28)
bst1.insert(90)
bst1.insert(3)
bst1.insert(18)
bst1.insert(45)
bst1.insert(41)
bst1.insert(48)
bst1.insert(30)
bst1.insert(50)
bst1.insert(38)
bst1.insert(33)
bst1.insert(32)
bst1.insert(36)
bst1.pre_order_traverse()       # 결과를 도식화 할 것
bst1.delete(28)
print(' ')
bst1.in_order_traverse()         # 결과를 도식화 할 것
bst1.delete(30)
print(' ')
bst1.post_order_traverse()