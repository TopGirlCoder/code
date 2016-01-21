require_relative('../pig_latin')

describe 'Converting single words to Pig Latin' do
 context "when converting a single word to pig latin with a starting vowel it returns the word" do
   it "responds with the word" do
     expect(convert_word_to_pig_latin "and").to eq "and"
   end
 end
   context "when converting a single word to pig latin without a starting vowel" do
   it "moves the starting letter to the end and adds ay " do
     expect(convert_word_to_pig_latin "dog").to eq "ogday"
   end
 end
end

 describe 'Converting a sentence to Pig Latin' do
 context "when converting a sentance pig latin each word in that sentance will return as pig latin" do
   it "responds with pig latin sentence" do
     expect(convert_sentence_to_pig_latin "today i will go to the beach").to eq "odaytay i illway ogay otay ethay eachbay"
   end
 end
 end
