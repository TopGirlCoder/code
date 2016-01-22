class Die
  DEFAULT_SIDES = 6

  attr_accessor :value, :sides

  def initialize(sides)
    if sides <= 0 || nil
      @sides = DEFAULT_SIDES
    else
      @sides = sides
    end
  end

  def roll
    rand(1..sides)
  end
end
