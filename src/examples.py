import torch

print(torch.cuda.is_available())
print(torch.zeros(1).cuda())

# The ID of the current GPU.
id = torch.cuda.current_device()
print( id )

# The name of the specified GPU, where id is an integer.
print(torch.cuda.get_device_name(id) )

# The memory address of the specified GPU, where id is an integer.
print(torch.cuda.device(id))

# The amount of GPUs that are accessible.
print(torch.cuda.device_count())


 
     
       