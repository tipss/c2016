package linkedlist101

import (
	"testing"
	"github.com/stretchr/testify/assert"
)
/*
Install this first
sudo chmod -R 777 go/
go get github.com/stretchr/testify/assert

e.g how to use :
go test ./linkedlist101.go linkedlist101_test.go -v
*/

func TestReverse(t *testing.T) {
	var head *node
	head = llAdd(head, 1)
	head = llAdd(head, 2)
	head = llAdd(head, 3)
	nhead := llReverse(head)
	
	assert.Equal(t, (*nhead).val, 3)
	assert.NotNil(t, nhead.next)
	assert.Equal(t, nhead.next.val, 2)
	assert.NotNil(t, nhead.next.next)
	assert.Equal(t, nhead.next.next.val, 1)
	assert.Nil(t, nhead.next.next.next)
}
