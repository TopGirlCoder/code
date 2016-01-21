# CONVERT SINGLE WORD
# IF the word starts with a vowel, return the word.
# ELSE return the word's pig latin equivalent.
#   MOVE all leading consonants to the end of the word
#   and add the suffix "ay."
# ENDIF	

def convert_word_to_pig_latin(word)

  vowels = ["a","e","i","o","u"]
  array_word =  word.split('')
  first_letter = word.split('').first
  new_word = []
  if vowels.include?(first_letter)
    word
  else
    until vowels.include?(first_letter) do
      new_word.push(first_letter)
      array_word.delete(first_letter)
      first_letter = array_word.first
    end
    pig_latin = array_word + new_word + ["ay"]
    pig_latin.join
  end
end

def convert_sentence_to_pig_latin (sentence)
  new_array = sentence.split(' ')
  pig_sentence = []
  new_array.each do |i|
    pig_sentence << convert_word_to_pig_latin(i)
  end
p pig_sentence.join(' ')
end
