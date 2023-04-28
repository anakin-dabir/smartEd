import React, { useState,useEffect, useContext } from 'react'

import { useParams } from 'react-router-dom'
import axios from 'axios';
import toast  from 'react-hot-toast';
import { Context } from '../Provider';
const Course = () => {
  const {provider} = useContext(Context);
    const {id} = useParams();
    const [data,setState] = useState({});
    const [isLoader, setIsLoader]= useState(false);
    
    useEffect(()=>{
        (async () => {
            setIsLoader(true);
            try {
                const response = await axios.post(`http://localhost:9999/course/getCourse`, {id}, { withCredentials: true });
                const { body } = response.data;
                console.log(body);
                setState(body);
            } catch (err) {
                
            }
            setIsLoader(false);
        })()
    },[])


const [file, setFile] = useState(null);
const [type, settype] = useState('');
const [detail, setdetail] = useState('');
const [deadline, setdeadline] = useState('');


const handleSubmit = async (e) => {
  e.preventDefault();
  const formData = new FormData();
  formData.append('type', type);
  formData.append('detail', detail);
  formData.append('deadline', deadline);
  formData.append("id", id);
  formData.append('image', file);
  try {
      const response = await axios.post('http://localhost:9999/course/addContent', formData, { withCredentials: true });
      const { msg, body } = response.data;
      console.log(body);
      setState(prev=> ({...prev, content:[...prev.content, body]}));
      toast.success(msg);

  }
  catch (err) {
      toast.error(err.response.data.msg);

  }
}
   



  return isLoader ? 'loading' : (<>
<section className=" body-font overflow-hidden">
  <div className="container px-5 py-24 mx-auto lg:max-w-screen-xl">
    <div className="bg-base-300 text-base-content flex-col text-2xl h-20 font-bold flex gap-1 items-center justify-center relative " >
        <div>{data.name}</div>
        <div className='text-sm font-normal'>By: {data.instructor?.name}</div>
    </div>
    <div className=" divide-y-2 divide-gray-100">

{data.content?.map(content =>{
    return(
        <CourseModule key={content._id} content={content}/>
    )
})}

{provider.currentUser.isOrg &&
    <label htmlFor="my-modal-7" className="btn btn-circle right-8 bottom-8 btn-primary fixed">+</label>
}
      
    </div>
  </div>
</section>




<input type="checkbox" id="my-modal-7" className="modal-toggle" />
            <label htmlFor="my-modal-7" className="modal cursor-pointer">
                <label className="modal-box relative" htmlFor="">
                    <h3 className="text-lg font-bold">Add Course Content</h3>
                    <form onSubmit={handleSubmit}>
                        
                        <div className="mt-4 form-control">
                            <label className="label">Type</label>
                            <input value={type} onChange={(e)=>settype(e.target.value)} placeholder="Type here" className="input border-0 border-b-2 border-b-primary focus:outline-none w-full" />
                        </div>
                        <div className="mt-4 form-control">
                            <label className="label">Detail</label>
                            <input  value={detail} onChange={(e)=>setdetail(e.target.value)} placeholder="Type here" className="input border-0 border-b-2 border-b-primary focus:outline-none w-full" />
                        </div>
                        <div className="mt-4 form-control">
                            <label className="label">Deadline</label>
                            <input  value={deadline} onChange={(e)=>setdeadline(e.target.value)} placeholder="Type here" className="input border-0 border-b-2 border-b-primary focus:outline-none w-full" />
                        </div>

                        <div className="form-control w-full max-w-xs">
  <label className="label">
    Related File
  </label>
  <input type="file" name='image' onChange={(e) => setFile(e.target.files[0])} className="file-input file-input-bordered w-full max-w-xs" />
  
</div>
                        <button type='submit' className={`mt-6  btn`}>Save</button>
                    </form>
                </label>
            </label>

            

</>

  )
}

export default Course
const CourseModule = ({content}) => {


  
    return (
      <>
      <div className="py-8 flex mt-6 bg-base-200 rounded-lg flex-wrap md:flex-nowrap">
          <div className="md:w-64 md:mb-0 mb-6 flex-shrink-0 flex flex-col">
            <span className="font-bold title-font pl-8 text=base-content">{content.type}</span>
          </div>
          <div className="md:flex-grow">
            <h2 className="text-2xl  text-base-content title-font mb-2">{content.detail}</h2>
            <p className="bg-primary inline-flex items-center mt-4">
              {content.deadline}
            </p>
            File:<p className="text-md underline rounded-lg"> {content.file}</p>
          </div>
          <div className='mr-32 pr-32'>
         Assignment Uploaded: 
        </div>
    <label htmlFor="my-modal-8" className="btn mr-2 btn-circle btn-primary">+</label>
        </div>


        <input type="checkbox" id="my-modal-8" className="modal-toggle" />
            <label htmlFor="my-modal-8" className="modal cursor-pointer">
                <label className="modal-box relative" htmlFor="">
                    <h3 className="text-lg font-bold">Submit Your Assignment</h3>
                    <form>
                      <div className="form-control w-full max-w-xs">
             <label className="label">
    Submit Assignment
  </label>
  <input type="file" name='image'  className="file-input file-input-bordered w-full max-w-xs" />
  
</div>
                        <button type='submit' className={`mt-6  btn`}>Save</button>
                    </form>
                    </label>
            </label>
          
        </>
    )







    
  }