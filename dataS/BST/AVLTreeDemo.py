from AVLTree import AVLTree

bst1 = AVLTree()
bst1.insert(10)
bst1.insert(20)
bst1.insert(5)
bst1.insert(80)
bst1.insert(90)
bst1.insert(7550)
bst1.pre_order_traverse()     # 결과를 도식화 할 것
bst1.insert(30)
bst1.insert(77)
bst1.insert(15)
bst1.in_order_traverse()       # 결과를 도식화 할 것
print(' ')
bst1.insert(40)
bst1.delete(7550)
bst1.delete(10)
bst1.post_order_traverse()   # 결과를 도식화 할 것
print(' ')
bst1.delete(5)
bst1.pre_order_traverse()    # 결과를 도식화 할 것
print(' ')
# 코드 11-2