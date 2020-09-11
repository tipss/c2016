
//Method 1 Copy an array note you need to have dst of length of souce or more
arr := []int{1, 2, 3}
tmp := make([]int, len(arr))
copy(tmp, arr)
fmt.Println(tmp)
fmt.Println(arr)
//Method 2: Use append, which will create a new slice
//Very useful remember, 
arr := []int{1, 2, 3}
tmp := append([]int(nil), arr...)  // Notice the ... splat
fmt.Println(tmp)
fmt.Println(arr)
