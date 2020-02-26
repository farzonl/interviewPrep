package main

import (
    "fmt"
)

func sumToN(inputArr []int, n int)[][2]int {
  indexMap := make(map[int]bool)
  inputArrLen := len(inputArr)

  for i := 0; i < inputArrLen; i++ {
    indexMap[inputArr[i]] = true
  }
  

  pairs := [][2]int{}
  for i := 0; i < inputArrLen; i++ {
    needed := n - inputArr[i];

    if (indexMap[needed]) { //&& inputArr[i] != needed) {
      pair := [2]int{inputArr[i], needed}
      pairs = append(pairs, pair)
    }    
  }
  return pairs;
}

func main() {
  a := []int{3, 5, 2, 6}
  fmt.Println(sumToN(a,10))

  b := []int{3, 5, 2, 6, 7}
  fmt.Println(sumToN(b,10))
}
