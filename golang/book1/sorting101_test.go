package sorting101

import (
	"fmt"
	"testing"
	"github.com/stretchr/testify/assert"
)

func TestBubbleSort(t *testing.T) {
	a := []int{5,5,4,4,3,3,2,2,1,1,0,0}
	//Sort ascending
	fmt.Println(a)
	l := len(a)
	sortBubbleSort(a)
	fmt.Println(a)
	assert.Equal(t, len(a), l)
	assert.Equal(t, a[0], 0)
	assert.Equal(t, a[l-1], 5)
}
