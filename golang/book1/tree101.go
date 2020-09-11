/*
* Implement binary search tree, 1. Insert, 2. Create, 3. Delete, 4. InOrder, 5. FindMax, 6. FindMin
 */
package main

import (
	"fmt"
	"log"
	"log/syslog"
	"math/rand"
	"os"
	"path/filepath"
	"time"
)

type node struct {
	val   int
	count int
	left  *node
	right *node
}

/* Recursive */
func Insert(r *node, val int) *node {

	if r == nil {
		r = &node{val, 0, nil, nil}
	} else if val > (*r).val {
		r.right = Insert(r.right, val)
	} else if val < (*r).val {
		r.left = Insert(r.left, val)
	} else {
		(*r).count++
	}
	return r
}

//Recursive
func Delete(r *node, val int) *node {
	if r == nil {
		return nil
	}
	if val > (*r).val {
		r.right = Delete(r.right, val)
	} else if val < (*r).val {
		r.left = Delete(r.left, val)
	} else { //Found Node
		//ONly one node
		if r.right == nil {
			tmp := (*r).left
			(*r).left = nil
			return tmp
		} else if (*r).left == nil {
			tmp := (*r).right
			(*r).right = nil
			return tmp
		} else {
			//Both node, Find successor
			tmp := FindMin((*r).right)
			(*r).val = (*tmp).val
			(*r).count = (*tmp).count
			(*r).right = Delete((*r).right, (*tmp).val)
			return r
		}
	}
	return r
}
func Create(num_nodes int) *node {
	var tree *node
	defer fmt.Printf("\nDone Insert\n")
	rand.Seed(time.Now().Unix())
	nums := make([]int, 0)
	for i := 0; i < num_nodes; i++ {
		k := rand.Intn(2 * num_nodes)
		fmt.Printf("%d ", k)
		tree = Insert(tree, k)
		nums = append(nums, k)
		if tree.left != nil && tree.right != nil {
			fmt.Printf("root->left %d root %d, root->right %d\n",
				(*tree).left.val, (*tree).val, (*tree).right.val)
		} else if tree.right != nil {
			fmt.Printf("root->left NULL root %d, root->right %d\n",
				(*tree).val, (*tree).right.val)
		} else if tree.left != nil {
			fmt.Printf("root->left %d root %d, root->right NULL\n",
				(*tree).left.val, (*tree).val)
		} else {
			fmt.Printf("root->left NULL root %d, root->right NULL\n",
				(*tree).val)
		}
		//fmt.Println("Begin")
		//InOrder(tree)
		//fmt.Println("End")
	}
	fmt.Println(nums)
	return tree
}

func Count(r *node) int {
	if r == nil {
		return 0
	}
	lc := Count(r.left)
	rc := Count(r.right)
	return lc + rc + 1
}

func InOrder(r *node) {
	if r == nil {
		return
	}
	InOrder(r.left)
	fmt.Printf("%d(%d), ", (*r).val, (*r).count)
	InOrder(r.right)
}

func FindMin(r *node) *node {
	if r.left != nil {
		return FindMin(r.left)
	}
	return r
}

func FindMax(r *node) *node {
	if r.right != nil {
		return FindMax(r.right)
	}
	return r
}

func Depth(r *node) int {
	var d int
	if r == nil {
		return d
	}
	rc := Depth(r.right)
	lc := Depth(r.left)
	if rc > lc {
		d = rc + 1
	} else {
		d = lc + 1
	}
	return d
}

func printPerLevel(r *node, level int) {
	if r == nil || level == 0 {
		return
	}
	if level == 1 {
		fmt.Printf(" %d ", (*r).val)
	}
	printPerLevel(r.left, level-1)
	printPerLevel(r.right, level-1)
}

// Uses Depth, printPerLevel, non recursive
func TreePrint(r *node) {
	fmt.Println()
	d := Depth(r)
	for i:=0; i <= d; i++ {
		k := d - i
		for k > 0 {
			fmt.Print(" ")
			k--
		}
		printPerLevel(r, i)
		fmt.Println()
	}
}
func main() {

	programName := filepath.Base(os.Args[0])
	sysLog, err := syslog.New(syslog.LOG_INFO|syslog.LOG_LOCAL7, programName)
	r := Create(10)
	if err != nil {
		log.Fatal(err)
	} else {
		log.SetOutput(sysLog)
	}
	fmt.Printf("root->left %d root %d, root->right %d\n",
		(*r).left.val, (*r).val, (*r).right.val)
	InOrder(r)
	TreePrint(r)
	fmt.Printf("Number of Nodes %d, Depth %d\n", Count(r), Depth(r))
	min := FindMin(r)
	max := FindMax(r)
	if max != nil && min != nil {
		fmt.Printf("max %d ", (*max).val)
		fmt.Printf("min %d\n", (*min).val)
		r = Delete(r, (*max).val)
		fmt.Printf("Nodes after max del, %d Depth %d\n", Count(r), Depth(r))
		InOrder(r)
		TreePrint(r)
		r = Delete(r, (*min).val)
		fmt.Printf("Nodes after min del, %d Depth %d\n", Count(r), Depth(r))
		InOrder(r)
		TreePrint(r)
	}

}
