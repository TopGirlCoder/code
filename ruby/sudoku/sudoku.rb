require 'pp'

class Sudoku
  
  attr_reader :board
  
  def initialize(board_string)
    @board = []
    board_string = board_string.chars
    board_size = Math.sqrt(board_string.length).to_i
    board_size.times do
     @board << board_string.shift(9)
    end
  end

  def subgrids
    @long_board = @board.flatten 
    subgrid = []
    index = 0
    num_first = 0
    num_last = 2
    3.times do
      3.times do
        subgrid[index] = (@long_board[num_first..num_last] + @long_board[(num_first+9)..(num_last+9)] + @long_board[(num_first+18)..(num_last+18)])
        index += 1
        num_first += 3
        num_last += 3
      end
      num_first += 18
      num_last += 18
    end
    @subgrid = subgrid
  end

  def check
    self.subgrids
    while @board.flatten.include?("-")
      @board.each_with_index do |row, row_index|
        row.each_with_index do |cell, cell_index|
          if cell == "-"
            all_num = ["1","2","3","4","5","6","7","8","9"]
            column = @board.transpose
            larger_array = @board[row_index].zip(column[cell_index]).flatten
            larger_array += @subgrid[((row_index/3)*3) + cell_index/3]
            all_num.reject! do |num|
              larger_array.include?(num)
            end
            if all_num.length == 1
              @board[row_index][cell_index] = all_num
              self.subgrids
            end
          end
        end
      end
    end
  end
  
  def solve
    final_board = []
    self.check
    string = @board.flatten
    board_size = Math.sqrt(string.length).to_i
    board_size.times do
      final_board << string.shift(9)
    end
    pp final_board
  end

end

sudoku = Sudoku.new("1-58-2----9--764-52--4--819-19--73-6762-83-9-----61-5---76---3-43--2-5-16--3-89--")
sudoku2 = Sudoku.new("29-5----77-----4----4738-129-2--3-648---5--7-5---672--3-9--4--5----8-7---87--51-9")
sudoku3 = Sudoku.new("6-873----2-----46-----6482--8---57-19--618--4-31----8-86-2---39-5----1--1--4562--")

sudoku.solve
sudoku2.solve
sudoku3.solve