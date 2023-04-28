import React, { useContext, useEffect,useState } from 'react'
import axios from 'axios';
import { Link } from 'react-router-dom';
import toast  from 'react-hot-toast';
import { Context } from './Provider';

const Home = () => {
const{provider} = useContext(Context);
    const [course, setCourse] = useState([]);
    const [isLoader, setIsLoader]= useState(false);
    const [title, setTitle] = useState('');
const [desc, setDesc] = useState('');
    useEffect(()=>{
        (async () => {
            setIsLoader(true);
            try {
              if(provider.currentUser.isOrg) { 
                const response = await axios.post(`http://localhost:9999/course/getAll`, {}, { withCredentials: true });
                const { body } = response.data;
                console.log(body);
                setCourse(body);}
                else{
                  const response = await axios.post(`http://localhost:9999/course/getSAll`, {}, { withCredentials: true });
                  const { body } = response.data;
                  console.log(body);
                  setCourse(body);
                }
            } catch (err) {
                
            }
            setIsLoader(false);
        })()
    },[])

const [isLoading, setIsLoading] = useState(false);
const handleSubmit= async(e)=>{
e.preventDefault();
setIsLoading(true);
try{
const response = await axios.post(`http://localhost:9999/course/addCourse`, {name:title, details:desc}, {withCredentials:true});
const {msg, body} = response.data;
setCourse(prev=>[...prev, body]);
toast.success(msg);
}catch(err){
  toast.error(err.response.data.msg);
}
setIsLoading(false);
}

  return isLoader ? 'Loading...': (
<>
  <div className="container lg:max-w-screen-xl px-5 py-24 mx-auto">
    <div className="flex flex-wrap w-full mb-20 flex-col items-center text-center">
      <h1 className="sm:text-3xl !text-4xl  title-font mb-2 font-bold text-base-content">SmartEd Web Application</h1>
      <p className="lg:w-1/2 w-full leading-relaxed text-base-content">Nuild with Mern Stach etce etc etc</p>
    </div>
    <div  className="flex flex-wrap -m-10">

    {course.map(course=>{
    return(
      
      <div key={course._id} className="xl:w-1/3 md:w-1/2 p-4">
        <div className="bg-neutral bg-opacity-50 shadow-lg p-6">
        {!provider.currentUser.isOrg ? course.students.includes(provider.currentUser) ? 
        
          <>
          <Link to={`/course/${course._id}`} className="text-lg hover:underline  text-base-content font-medium title-font mb-2">{course.name}</Link>
          <p className="leading-relaxed text-base">{course.details}</p>
          </>
        
         :
         
          <>
          <p  className="text-lg   text-base-content font-medium title-font mb-2">{course.name}</p>
          <p className="leading-relaxed text-base">Not Enrolled</p>
          </>
          :
          <>
          <Link to={`/course/${course._id}`} className="text-lg hover:underline  text-base-content font-medium title-font mb-2">{course.name}</Link>
          <p className="leading-relaxed text-base">{course.details}</p>
          </>
         }
          
          
        </div>
      </div>
     
    
    )
    })}
    </div>
    {provider.currentUser.isOrg && 
    <label htmlFor="my-modal-6" className="btn btn-circle right-8 bottom-8 btn-primary fixed">+</label>
}
  
    </div>



    <input type="checkbox" id="my-modal-6" className="modal-toggle" />
            <label htmlFor="my-modal-6" className="modal cursor-pointer">
                <label className="modal-box relative" htmlFor="">
                    <h3 className="text-lg font-bold">Add Course</h3>
                    <form onSubmit={handleSubmit}>
                        
                        <div className="mt-4 form-control">
                            <label className="label">Course Title</label>
                            <input onChange={(e) => setTitle(e.target.value)} value={title}  type="text" placeholder="Type here" className="input border-0 border-b-2 border-b-primary focus:outline-none w-full" />
                        </div>
                        <div className="mt-4 form-control">
                            <label className="label">Description</label>
                            <input onChange={(e) => setDesc(e.target.value)} value={desc}  type="text" placeholder="Type here" className="input h-24 border-0 border-b-2 border-b-primary focus:outline-none w-full" />
                        </div>
                        <button type='submit' className={`mt-6 ${isLoading && 'loading'} btn`}>Save</button>
                    </form>
                </label>
            </label>



</>


  )
}

export default Home


const Course = ({course}) =>{
    return(
<div className="flex flex-wrap -m-10">
      <div className="xl:w-1/3 md:w-1/2 p-4">
        <div className="bg-base-200 bg-opacity-50 shadow-lg p-6">
          
          <Link to={`/course/${course._id}`} className="text-lg hover:underline  text-base-content font-medium title-font mb-2">{course.name}</Link>
          <p className="leading-relaxed text-base">{course.details}</p>
        </div>
      </div>
     
    </div>
    )
}