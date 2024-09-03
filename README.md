目录：

1.【removeElement.c】27. 移除元素：给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素。元素的顺序可能发生改变。然后返回nums中与val不同的元素的数量。
nums中不等于val的元素数量为k，要通过此题，您需要执行以下操作：更改nums数组，使nums的前k个元素包含不等于val的元素。nums 的其余元素和nums的大小并不重要。返回k;

2.【removeDuplicates.c】26. 删除有序数组中的重复项：给你一个非严格递增排列的数组nums，请你原地删除重复出现的元素，使每个元素只出现一次，返回删除后数组的新长度。
元素的相对顺序应该保持一致。然后返回nums中唯一元素的个数。考虑nums的唯一元素的数量为k，你需要做以下事情确保你的题解可以被通过：更改数组nums，
使nums的前k个元素包含唯一元素，并按照它们最初在nums中出现的顺序排列。nums的其余元素与nums的大小不重要。返回k;

3.【addToArrayForm.c】989. 数组形式的整数加法：整数的数组形式num是按照从左到右的顺序表示其数字的数组。例如，对于num=1321，数组形式是 [1,3,2,1]。
给定num，整数的数组形式，和整数k，返回整数num+k的数组形式；

4.【reverseList.c】206. 反转链表：给你单链表的头节点head，请你反转链表，并返回反转后的链表。（三指针移位法和头插法）；

5.【removeElements.c】203. 移除链表元素：给你一个链表的头节点head和一个整数val，请你删除链表中所有满足Node.val==val的节点，并返回新的头节点；

6.【middleNode.c】876. 链表的中间结点：给你单链表的头结点head，请你找出并返回链表的中间结点。如果有两个中间结点，则返回第二个中间结点；

7.【kthToLast.c】面02.02. 返回倒数第k个节点：实现一种算法，找出单向链表中倒数第k个节点。返回该节点的值；

8.【trainingPlan1.c】LCR 140. 训练计划II：给定一个头节点为head的链表用于记录一系列核心肌群训练项目编号，请查找并返回倒数第cnt个训练项目编号；

9.【mergeTwoLists.c】21. 合并两个有序链表：将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的；（核心思想：取小的节点下来尾插或选择带哨兵位的头节点）

10.【partition.c】86. 分隔链表：给你一个链表的头节点head和一个特定值x，请你对链表进行分隔，使得所有小于x的节点都出现在大于或等于x的节点之前。你应当保留两个分区中每个节点的初始相对位置；

11.【isPalindrome.c】LCR 027. 回文链表：给定一个链表的头节点head，请判断其是否为回文链表。如果一个链表是回文，那么链表节点序列从前往后看和从后往前看是相同的；（之前题目的变形，利用快慢指针+链表逆置）

12.【getIntersectionNode.c】160. 相交链表：给你两个单链表的头节点headA和headB，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回null。（核心思想：让长的链表的指针先走差值步，保证了两链表指针同时到达相交节点）

13.【hasCycle1.c】141. 环形链表：给你一个链表的头节点head，判断链表中是否有环。如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。为了表示给定链表中的环，评测系统内部使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。注意：pos不作为参数进行传递。仅仅是为了标识链表的实际情况。如果链表中存在环，则返回true。否则返回false。（常考题之一，核心思想：快慢指针）

14.【detectCycle.c】142. 环形链表II：给定一个链表的头节点head，返回链表开始入环的第一个节点。如果链表无环，则返回null。如果链表中有某个节点，可以通过连续跟踪next指针再次到达，则链表中存在环。为了表示给定链表中的环，评测系统内部使用整数pos来表示链表尾连接到链表中的位置（索引从0开始）。如果pos是-1，则在该链表中没有环。注意：pos不作为参数进行传递，仅仅是为了标识链表的实际情况。不允许修改链表。

15.【copyRandomList.c】138. 随机链表的复制：给你一个长度为n的链表，每个节点包含一个额外增加的随机指针random，该指针可以指向链表中的任何节点或空节点。构造这个链表的深拷贝。深拷贝应该正好由n个全新节点组成，其中每个新节点的值都设为其对应的原节点的值。新节点的next指针和random指针也都应指向复制链表中的新节点，并使原链表和复制链表中的这些指针能够表示相同的链表状态。复制链表中的指针都不应指向原链表中的节点 。

16.【insertionSortList.c】147. 对链表进行插入排序：给定单个链表的头head，使用插入排序对链表进行排序，并返回排序后链表的头。（核心思想：依次从后面（第二个开始，第一个当默认的头）取一个节点在前面合适位置插入）

17.【deleteDuplicates1.c】83. 删除排序链表中的重复元素：给定一个已排序的链表的头head，删除所有重复的元素，使每个元素只出现一次。返回已排序的链表。

18.【deleteDuplicates2.c】82. 删除排序链表中的重复元素II：给定一个已排序的链表的头head，删除原始链表中所有重复数字的节点，只留下不同的数字。返回已排序的链表 。

19.【isValid.c】20. 有效的括号：给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串s，判断字符串是否有效。有效字符串需满足：左括号必须用相同类型的右括号闭合。左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。

20.【queue2stack.c】225. 用队列实现栈：请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（push、top、pop和empty）。实现MyStack类：void push(int x) 将元素x压入栈顶。int pop()移除并返回栈顶元素。int top()返回栈顶元素。bool eanempty() 如果栈是空的，返回true；否则返回false。

21.【stack2queue.c】232. 用栈实现队列：请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（push、pop、peek、empty）。实现MyQueue类：void push(int x) 将元素x推到队列的末尾。int pop()从队列的开头移除并返回元素。int peek()返回队列开头的元素。bool eanempty()如果队列为空，返回true；否则返回false。

22.【myCircularQueue.c】622. 设计循环队列：设计你的循环队列实现。循环队列是一种线性数据结构，其操作表现基于FIFO（先进先出）原则并且队尾被连接在队首之后以形成一个循环。它也被称为“环形缓冲器”。循环队列的一个好处是我们可以利用这个队列之前用过的空间。在一个普通队列里，一旦一个队列满了，我们就不能插入下一个元素，即使在队列前面仍有空间。但是使用循环队列，我们能使用这些空间去存储新的值。你的实现应该支持如下操作：MyCircularQueue(k):构造器，设置队列长度为k。Front:从队首获取元素。如果队列为空，返回-1。Rear:获取队尾元素。如果队列为空，返回-1。enQueue(value):向循环队列插入一个元素。如果成功插入则返回真。deQueue():从循环队列中删除一个元素。如果成功删除则返回真。isEmpty():检查循环队列是否为空。isFull():检查循环队列是否已满。

23.【smallestK.c】面17.14. 最小K个数：设计一个算法，找出数组中最小的k个数。以任意顺序返回这k个数均可。（核心思想：建堆）

24.【preorderTraversal.c】144. 二叉树的前序遍历：给你二叉树的根节点root，返回它节点值的前序遍历。

25.【isUnivalTree.c】965. 单值二叉树：如果二叉树每个节点都具有相同的值，那么该二叉树就是单值二叉树。只有给定的树是单值二叉树时，才返回true；否则返回false。

26.【maxDepth.c】104. 二叉树的最大深度：给定一个二叉树root，返回其最大深度。二叉树的最大深度是指从根节点到最远叶子节点的最长路径上的节点数。

27.【invertTree.c】226. 翻转二叉树：给你一棵二叉树的根节点root，翻转这棵二叉树，并返回其根节点。（镜像翻转当前树+递归翻转左右树或借助返回值）

28.【isSameTree.c】100. 相同的树：给你两棵二叉树的根节点p和q ，编写一个函数来检验这两棵树是否相同。如果两个树在结构上相同，并且节点具有相同的值，则认为它们是相同的。

29.【isSubtree.c】572. 另一棵树的子树：给你两棵二叉树root和subRoot。检验root中是否包含和subRoot具有相同结构和节点值的子树。如果存在，返回true ；否则返回false。二叉树tree的一棵子树包括 tree的某个节点和这个节点的所有后代节点。tree也可以看做它自身的一棵子树。

30.【isBalanced.c】110. 平衡二叉树：给定一个二叉树，判断它是否是平衡二叉树。（常考题之一，与另一棵树的子树题目类似，前序或者后序）

31.【sortArray.c】912. 排序数组：给你一个整数数组nums，请你将该数组升序排列。

32.【reverseOnlyLetters.cpp】917. 仅仅反转字母：给你一个字符串s，根据下述规则反转字符串：所有非英文字母保留在原有位置。所有英文字母（小写或大写）位置反转。返回反转后的s。

33.【firstUniqChar.cpp】387. 字符串中的第一个唯一字符：给定一个字符串s，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回-1。（非常经典的一道题，核心思想：使用映射统计次数）

34.【isPalindrome.cpp】125. 验证回文串：如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个回文串。字母和数字都属于字母数字字符。给你一个字符串s，如果它是回文串，返回true；否则返回false。

35.【addStrings.cpp】415. 字符串相加：给定两个字符串形式的非负整数num1和num2，计算它们的和并同样以字符串形式返回。你不能使用任何內建的用于处理大整数的库（比如BigInteger），也不能直接将输入的字符串转换为整数形式。

36.【singleNumber1.c】136. 只出现一次的数字：给你一个非空整数数组nums，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

37.【singleNumber1.cpp】136. 只出现一次的数字：给你一个非空整数数组nums，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。你必须设计并实现线性时间复杂度的算法来解决此问题，且该算法只使用常量额外空间。

38.【singleNumber2.cpp】137. 只出现一次的数字II：给你一个整数数组nums，除某个元素仅出现一次外，其余每个元素都恰出现三次。请你找出并返回那个只出现了一次的元素。你必须设计并实现线性时间复杂度的算法且使用常数级空间来解决此问题。

39.【singleNumber3.c】260. 只出现一次的数字III：给你一个整数数组nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素。你可以按任意顺序返回答案。你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

40.【singleNumber3.cpp】260. 只出现一次的数字III：给你一个整数数组nums，其中恰好有两个元素只出现一次，其余所有元素均出现两次。找出只出现一次的那两个元素。你可以按任意顺序返回答案。你必须设计并实现线性时间复杂度的算法且仅使用常量额外空间来解决此问题。

41.【generate.cpp】118. 杨辉三角：给定一个非负整数numRows，生成杨辉三角的前numRows行。

42.【MinStack.cpp】155. 最小栈：设计一个支持push，pop，top操作，并能在常数时间内检索到最小元素的栈。实现MinStack类:MinStack()初始化堆栈对象。void push(int val)将元素val推入堆栈。void pop()删除堆栈顶部的元素。int top()获取堆栈顶部的元素。int getMin()获取堆栈中的最小元素。

43.【evalRPN.cpp】150. 逆波兰表达式求值：给你一个字符串数组tokens，表示一个根据逆波兰表示法表示的算术表达式。请你计算该表达式。返回一个表示表达式值的整数。

44.【findKthLargest.cpp】215. 数组中的第K个最大元素：给定整数数组nums和整数k，请返回数组中第k个最大的元素。请注意，你需要找的是数组排序后的第k个最大的元素，而不是第k个不同的元素。
你必须设计并实现时间复杂度为O(n)的算法解决此问题。（核心思想：建小堆，类似Top-K问题）

45.【tree2str.cpp】606. 根据二叉树创建字符串：给你二叉树的根节点root，请你采用前序遍历的方式，将二叉树转化为一个由括号和整数组成的字符串，返回构造出的字符串。空节点使用一对空括号对 "()" 表示，转化后需要省略所有不影响字符串与原始二叉树之间的一对一映射关系的空括号对。

46.【topKFrequent.cpp】692. 前K个高频单词：给定一个单词列表words和一个整数k，返回前k个出现次数最多的单词。返回的答案应该按单词出现频率由高到低排序。如果不同的单词有相同出现频率，按字典顺序排序。

47.【repeatedNTimes.cpp】961. 在长度2N的数组中找出重复N次的元素：给你一个整数数组nums，该数组具有以下属性：nums.length==2*n；nums包含n+1个不同的元素；nums中恰有一个元素重复n次。
找出并返回重复了n次的那个元素。
