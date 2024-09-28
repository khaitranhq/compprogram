package trappingrainwater

import (
	"errors"
	"fmt"

	"github.com/rs/zerolog"
	"github.com/rs/zerolog/log"
)

type Stack struct {
	data     []int
	topIndex int
}

func NewStack() *Stack {
	return &Stack{
		topIndex: -1,
	}
}

func (s *Stack) Push(element int) {
	s.data = append(s.data, element)
	s.topIndex++
}

func (s *Stack) Top() (int, error) {
	if s.topIndex < 0 {
		return -1, errors.New("Stack is empty")
	}
	return s.data[s.topIndex], nil
}

func (s *Stack) Size() int {
	return s.topIndex + 1
}

func (s *Stack) Pop() error {
	if len(s.data) > 0 {
		s.topIndex--
		s.data = s.data[:s.topIndex+1]
		return nil
	}
	return errors.New("Stack is empty")
}

func trap(height []int) int {
	zerolog.SetGlobalLevel(zerolog.InfoLevel)

	stack := NewStack()
	ans := 0
	for i := 0; i < len(height); i++ {
		beforeHeight := height[i]
		log.Debug().Msg(fmt.Sprintf("i = %d, height = %d", i, height[i]))

		for true {
			topIndex, err := stack.Top()
			if err != nil {
				break
			}

			ans += (min(height[topIndex], height[i]) - beforeHeight) * (i - topIndex - 1)
			beforeHeight = height[topIndex]

			if height[topIndex] > height[i] {
				break
			}

			stack.Pop()

		}

		log.Debug().Msg(fmt.Sprintf("ans = %d", ans))
		stack.Push(i)
		log.Debug().Msg("=========================")
	}
	return ans
}
