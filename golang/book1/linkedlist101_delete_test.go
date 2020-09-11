package linkedlist101
import (
	"fmt"
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestDelete2(t *testing.T){
	var head *node
	fmt.Println("About to start testing Delete")
	head = llAdd(head, 1)
	head = llAdd(head, 2)
	head = llAdd(head, 3)
	head = llAdd(head, 4)
	head = llAdd(head, 5)
	llPrint(head)
	mid := llFindMiddleNode(head)
	if mid == nil {
		assert.Nil(t, head)
	}
	val := (*mid).val
	llDeleteNode2(mid)
	n := llFindNode(head, val)
	if n != nil {
		fmt.Printf("Found node with val %d %p\n", (*n).val, n)
	}
	assert.Nil(t, n)
}
