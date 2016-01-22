get '/' do
  @die = Die.new(0)	
  erb :index
end

post '/rolls' do
  @die = Die.new(params[:sides].to_i)
  #post request
  if request.xhr?
    content_type :json
    {value: @die.roll}.to_json
  else
    erb :index
  end
end  
