//package linkedlist101

//Comment out the above line and uncommetn if you want to use standalone
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type node struct {
	val  int
	next *node
}

/*
* How it works.
* We know , k, head of ll,
* we do not know n.
* We do not want to find n, as it can become an expensive walks project,
* Answer is: walk n-k elements from head.
*
* When we walk k elements from the beginning , we know that, we have n-k elements to walk
* till the end of the list.
* So first walk k elements.
* As a next step, walk from that node till the end of list is n-k elements.
* Means, at this step if you intialize a pointer to head, and move it along with
* this walk, you will at the kth element, when  you hit the end of list!.
 */
func llFindKthLastNode(head *node, k int) (nn int, kthnode *node) {
	f := head
	s := head
	for i := 0; i < k; i++ {
		f = f.next
	}
	for f != nil {
		s = s.next
		f = f.next
		k++
	}
	return k, s
}

//Remember very short
// inner loop adjust next ptr itself based on duplicates.
//Note you do not nee (*).val , as its struct pointer
func llDeleteDuplicate(head *node) *node {
	var outer *node
	var inner *node
	// o(n^2)
	for outer = head; outer != nil; outer = outer.next {
		//Remember to use for loop like this only
		for inner = outer; inner != nil; {
			if inner.next != nil && inner.next.val == outer.val {
				fmt.Printf("duplicate found outer.val is %d "+
					"inner.next.val is %d\n",
					outer.val, inner.next.val)
				inner.next = inner.next.next
			} else {
				inner = inner.next
			}
		}
	}
	return head
}

func llDeleteAll(head *node) *node {
	var nxt *node
	fmt.Println("\nDeleteAll-Start")
	for head != nil {
		nxt = head.next
		head.next = nil
		fmt.Printf("%d ", (*head).val)
		(*head).val = 0xbeef
		head = nxt
	}
	fmt.Println("\nDeleteAll-End")
	return nil
}
func llReverse(head *node) *node {
	var next, prev, current *node
	current = head
	for current != nil {
		next = (*current).next
		(*current).next = prev
		prev = current
		current = next
	}
	return prev
}

func llAdd(head *node, val int) *node {
	nn := &node{val, nil}
	if head == nil {
		return nn
	}
	tmp := head
	for tmp != nil {
		if tmp.next == nil {
			tmp.next = nn
			return head
		}
		tmp = tmp.next
	}
	return head
}

func llPrint(head *node) {
	for head != nil {
		fmt.Printf("%d->", (*head).val)
		head = head.next
	}
	fmt.Println("nil")
}

//Remember ,
//1 2 3 4 5 , with loop connecting 5 and 1,  it returns noes 1 and 5,
// Walk pattern of slow and fast
// 1,1 2,3 3,5 4,2 5,4 1,1(loop)
func llFindloop(head *node) (f *node, s *node) {
	var fast, slow, prev *node
	fast = head
	slow = head
	for slow != nil && fast != nil && fast.next != nil {
		prev = slow
		slow = slow.next
		fast = fast.next.next
		if slow == fast {
			return fast, prev
		}
	}
	return nil, nil
}

//Test function to create a loop, connects tail with head
func llAddloop(head *node) {
	tmp := head
	for tmp != nil {
		if tmp.next == nil {
			tmp.next = head
			return
		}
		tmp = tmp.next
	}
}

func llFindMiddleNode(head *node) *node {
	var fast, slow *node
	fast = head
	slow = head
	for fast != nil && fast.next != nil {
		fmt.Printf("slow %d fast %d\n", slow.val, fast.val)
		slow = slow.next
		fast = fast.next.next
	}
	return slow
}

func llFindNode(h *node, n int) *node {
	for h != nil {
		if (*h).val == n {
			return h
		}
		h = h.next
	}
	return nil
}

/*
*  n is not head,
* and its valid node of linked list,
* delete this node, no head is given
* Logic : copy next node value to this node till the end
*         and disconnect last node
 */
func llDeleteNode2(n *node) {
	prev := n
	if n.next == nil {
		fmt.Println("Can't delete last node wthout previous ptr")
		return
	}
	for n != nil {
		//its last node which we need to free
		if n.next == nil {
			if prev.next == nil {
				fmt.Printf("prev.next is nil, %d\n", prev.val)
			}
			prev.next = nil
			n.val = 0xbeef
			return
		}
		prev = n
		n.val = n.next.val
		n = n.next
	}
}

/* Partition ll nodes greater than x to right LL, and rest of them in left LL */
//TBD need more work
func llPartitionAtX(head *node, x int) (*node, *node) {
	var right *node
	var left  *node
	var tmp *node
	for head != nil {
		tmp = head.next
		if head.val > x {
			head.next = right
			right = head
		} else {
			head.next = left
			left = head
		}
		head = tmp
	}
	return left, right
}

//Rework, need fix TBD
func llAddTwoList(f *node, s *node) *node {
	var sum int
	var carry int
	var head *node
	var tmp *node
	/*
			989 is represneted as
			9->8->9-> nil
			123 is represented as
		        3->2->1-> nil
		===================
		        c2->c2->c2->
		        2->1->1->2-> nil
	*/
	for f != nil || s != nil {
		if f != nil {
			sum += f.val
		}
		if s != nil {
			sum += s.val
		}
		sum += carry
		if sum >= 10 {
			carry = 1
		} else {
			carry = 0
		}
		sum = sum % 10

		if head == nil {
			head = &node{sum, nil}
			tmp = head
		} else {
			tmp.next = &node{sum, nil}
		}
		if f != nil {
			f = f.next
		}
		if s != nil {
			s = s.next
		}
	}
	if carry > 0 {
		tmp.next = &node{carry, nil}
	}
	return head
}

func llPrintReverse(head *node) {
	if head == nil {
		return
	}
	llPrintReverse(head.next)
	fmt.Printf("%d ", head.val)
}

func main() {
	f := os.Stdin
	scanner := bufio.NewScanner(f)
	defer f.Close()
	var head *node
	for scanner.Scan() {
		fmt.Println(scanner.Text())
		str := strings.Split(scanner.Text(), " ")
		for _, s := range str {
			val, ok := strconv.Atoi(s)
			if ok == nil {
				head = llAdd(head, val)
			}
		}
		//TBD uncomment to test these
		//llPrint(head)
		//head = llReverse(head)
		//llPrint(head)
		n := llFindMiddleNode(head)
		if n != nil {
			fmt.Printf("Middle node is %d %p, will delete it now\n", (*n).val, n)
		}

		//Head is not given, assuming n is not head
		llDeleteNode2(n)
		fmt.Println("After deleting Middle node")
		llPrint(head)

		llAddloop(head)
		f, s := llFindloop(head)
		if f != nil && s != nil {
			fmt.Printf("Loop at this node %d %p pointing to %d %p\n",
				(*f).val, f, (*s).val, s)
			if s.next == head {
				s.next = nil //Fix loop ,
			}
		} else {
			fmt.Println("No loop detected")
		}
		fmt.Println("Deleting duplicates:")
		head = llDeleteDuplicate(head)
		var knode *node
		var count int
		count, knode = llFindKthLastNode(head, 3)
		fmt.Printf("nodes %d, kthnode value is %d %p is 3rd node from last\n",
			count, knode.val, knode)
		fmt.Println("Print Reverse")
		llPrintReverse(head)
		//TBD head = llAddTwoList(head, head)
		//fmt.Println("AddTwoList:")
		left, right :=llPartitionAtX(head, 3)
		llPrint(left)
		llPrint(right)
		head = llDeleteAll(head)
	}
}
